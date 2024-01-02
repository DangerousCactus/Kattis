#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  n++;

  vector<pair<ld, ld>> g(n);

  g[0] = {0, 0};
  rep(i, 1, n) {
    cin >> g[i].first >> g[i].second;
  }

  ld lo = 0;
  ld hi = 1E12;

  vector<vector<ld>> dist(n, vector<ld>(n));
  rep(i, 0, n) {
    rep(j, 0, n) {
      dist[i][j] = hypot(g[i].first - g[j].first, g[i].second - g[j].second);
    }
  }

  rep(zz, 0, 100) {
    auto mid = (lo + hi) / 2;

    vector<bool> vis(n, false);
    vi tin(n, -1), low(n, -1);
    int timer = 0;
    bool fail = false;

    function<void(int, int)> dfs = [&](int v, int p) {
      vis[v] = true;
      tin[v] = low[v] = timer++;

      rep(to, 0, n) {
        if (to == p || dist[v][to] >= mid)
          continue;
        if (vis[to]) {
          low[v] = min(low[v], tin[to]);
        } else {
          dfs(to, v);
          low[v] = min(low[v], low[to]);
          if (low[to] >= tin[v] && p != -1)
            fail = true;
        }
      }
    };

    dfs(0, -1);

    rep(i, 0, n) {
      fail = fail || !vis[i];
    }

    if (fail) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  cout << fixed << setprecision(15) << lo;
}