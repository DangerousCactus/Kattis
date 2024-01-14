#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template <class G, class F>
int dfs(int j, G& g, F& f) {
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
template <class G, class F>
void scc(G& g, F f) {
  int n = sz(g);
  val.assign(n, 0);
  comp.assign(n, -1);
  Time = ncomps = 0;
  rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  map<char, int> conv{{'A', 0},  {'2', 1},  {'3', 2}, {'4', 3}, {'5', 4},
                      {'6', 5},  {'7', 6},  {'8', 7}, {'9', 8}, {'T', 9},
                      {'J', 10}, {'Q', 11}, {'K', 12}};

  string s;
  cin >> s;

  vi si;
  for (auto& c : s) {
    si.push_back(conv[c]);
  }
  vector<vi> s2(7);

  rep(i, 0, sz(si)) {
    if (si[i] < 7) {
      s2[i].push_back(si[i]);
    }
  }

  vector<vi> comps;
  scc(s2, [&](vi a) { comps.push_back(a); });

  set<int> removed;

  rep(i, 0, sz(comps)) {
    rep(j, 0, sz(comps)) {
      if (i != j) {
        for (auto& x : comps[i]) {
          if (count(all(comps[j]), si[x])) {
            removed.insert(j);
          }
        }
      }
    }
  }

  vi deck;
  int extra = 45;

  rep(i, 0, sz(comps)) {
    if (removed.count(i)) {
      continue;
    }
    deck.push_back(0);
    for (auto& y : comps[i]) {
      deck.back() += 4 - count(all(si), y);
    }
    extra -= deck.back();
  }

  ld total = 0;

  function<ld(int)> fact = [&](int c) { return c == 0 ? 1 : c * fact(c - 1); };
  auto nCk = [&](int n, int k) { return fact(n) / (fact(k) * fact(n - k)); };

  function<void(int, int, int, ld)> solve = [&](int idx, int skip, int used,
                                                ld mul) {
    if (idx == sz(deck)) {
      rep(i, 0, extra + 1) {
        total += (used + i) * fact(used + i - 1) * fact(45 - (used + i)) * mul *
                 nCk(extra, i);
      }
      return;
    }

    if (idx == skip) {
      return solve(idx + 1, skip, used + 1, mul * deck[skip]);
    }

    rep(i, 0, deck[idx]) {
      solve(idx + 1, skip, used + i + 1, mul * nCk(deck[idx], i + 1));
    }
  };

  rep(i, 0, sz(deck)) {
    solve(0, i, 0, 1);
  }

  cout << fixed << setprecision(15) << total / fact(45);
}