#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pii> adj{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  int n, m;
  cin >> n >> m;

  vector<vector<bool>> g(n + 2, vector<bool>(m + 2));

  rep(i, 0, n) {
    rep(j, 0, m) {
      char c;
      cin >> c;
      if (c == 'X') {
        g[i + 1][j + 1] = true;
      }
    }
  }

  n += 2;
  m += 2;

  queue<pii> q;
  vector<vector<bool>> vis(n, vector<bool>(m));

  rep(i, 0, n) {
    rep(j, 0, m) {
      if (!g[i][j]) {
        q.emplace(i, j);
      }
    }
  }

  int ct = -1;
  while (sz(q)) {
    queue<pii> nq;

    while (sz(q)) {
      auto [x, y] = q.front();
      q.pop();

      for (auto &[dx, dy] : adj) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] &&
            !vis[nx][ny]) {
          nq.emplace(nx, ny);
          vis[nx][ny] = true;
        }
      }
    }
    q = nq;
    ct++;
  }

  cout << ct;
}