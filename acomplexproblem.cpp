#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template <class G, class F> int dfs(int j, G &g, F &f) {
  int low = val[j] = ++Time, x;
  z.push_back(j);
  for (auto e : g[j])
    if (comp[e] < 0)
      low = min(low, val[e] ?: dfs(e, g, f));
  if (low == val[j]) {
    do {
      x = z.back();
      z.pop_back();
      comp[x] = ncomps;
      cont.push_back(x);
    } while (x != j);
    f(cont);
    cont.clear();
    ncomps++;
  }
  return val[j] = low;
}
template <class G, class F> void scc(G &g, F f) {
  int n = sz(g);
  val.assign(n, 0);
  comp.assign(n, -1);
  Time = ncomps = 0;
  rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n;
  cin >> m >> n;
  unordered_map<string, int> mtoi;
  set<int> laxin;
  string s1, s2;

  vector<vi> lax(2 * (m + n)), strict(2 * (m + n));

  rep(i, 0, m) {
    cin >> s1 >> s2;
    if (!mtoi.count(s1)) {
      mtoi[s1] = sz(mtoi);
    }

    if (!mtoi.count(s2)) {
      mtoi[s2] = sz(mtoi);
    }

    lax[mtoi[s1]].push_back(mtoi[s2]);
  }

  rep(j, 0, n) {
    cin >> s1 >> s2;
    if (!mtoi.count(s1)) {
      mtoi[s1] = sz(mtoi);
    }

    if (!mtoi.count(s2)) {
      mtoi[s2] = sz(mtoi);
    }

    strict[mtoi[s1]].push_back(mtoi[s2]);
  }

  vector<vi> temp(sz(mtoi));
  rep(i, 0, sz(mtoi)) {
    for (auto &x : lax[i]) {
      temp[i].push_back(x);
    }

    for (auto &x : strict[i]) {
      temp[i].push_back(x);
    }
  }

  lax.resize(sz(mtoi));
  strict.resize(sz(mtoi));

  auto fc = [&](vi &x) {};
  scc(temp, fc);

  vector<vi> adjlax(ncomps), adjstrict(ncomps);

  rep(i, 0, sz(lax)) {
    for (auto &b : lax[i]) {
      if (comp[i] != comp[b]) {
        adjlax[comp[i]].push_back(comp[b]);
      }
    }
  }

  rep(i, 0, sz(strict)) {
    for (auto &b : strict[i]) {
      adjstrict[comp[i]].push_back(comp[b]);
    }
  }

  vi mn(ncomps + 5, 1);

  rep(i, 0, ncomps) {
    auto curr = ncomps - 1 - i;
    for (auto &x : adjlax[curr]) {
      mn[x] = max(mn[x], mn[curr]);
    }

    for (auto &x : adjstrict[curr]) {
      mn[x] = max(mn[x], mn[curr] + 1);
    }
  }

  // for (auto &x : mtoi) {
  //   cout << x.first << ':' << mn[comp[x.second]] << endl;
  // }

  cout << *max_element(all(mn)) << ' ' << ncomps;

  return 0;
}