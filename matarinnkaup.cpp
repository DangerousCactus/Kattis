#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 100007;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int u, k;
  cin >> u >> k;

  unordered_map<string, int> idm;
  vector<string> idv;
  auto id = [&idm, &idv](string& s) {
    if (idm.count(s)) {
      return idm[s];
    }
    idv.push_back(s);
    return idm[s] = sz(idm);
  };

  vector<vector<pii>> adj(MAXN);

  rep(i, 0, u) {
    string name, dish;
    int h, x;
    cin >> name >> h;

    rep(j, 0, h) {
      cin >> dish >> x;
      adj[id(name)].emplace_back(id(dish), x);
    }
  }

  vector<ll> ct(MAXN);

  rep(i, 0, k) {
    string name;
    int n, y;
    cin >> n;

    rep(j, 0, n) {
      cin >> name >> y;
      for (auto& [a, b] : adj[id(name)]) {
        ct[a] += y * b;
      }
    }
  }

  vector<pair<string, ll>> out;
  rep(i, 0, sz(idv)) {
    out.emplace_back(idv[i], ct[i]);
  }

  sort(all(out));

  for (auto& [a, b] : out) {
    if (b == 0) {
      continue;
    }
    cout << a << ' ' << b << '\n';
  }
}