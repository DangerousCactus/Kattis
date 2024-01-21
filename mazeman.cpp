#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const vector<pii> dirs = {{-1, 0},
                          {1,  0},
                          {0,  -1},
                          {0,  1}};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m >> ws;

  vector<pii> starts;
  vector<vector<bool>> vis(n, vector<bool>(m));
  vector<string> g(n);

  rep(i, 0, n) {
    getline(cin, g[i]);
    rep(j, 0, m) {
      if ('A' <= g[i][j] && g[i][j] <= 'W') {
        starts.emplace_back(i, j);
      }
    }
  }

  int needed = 0;

  for (auto &[sx, sy]: starts) {
    bool change = false;
    queue<pii> q;
    q.emplace(sx, sy);
    vis[sx][sy] = true;

    while (sz(q)) {
      auto [x, y] = q.front();
      q.pop();

      for (auto &[dx, dy]: dirs) {
        auto nx = x + dx, ny = y + dy;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) {
          continue;
        }

        if (g[nx][ny] != '.' && g[nx][ny] != ' ') {
          continue;
        }

        if (g[nx][ny] == '.') {
          change = true;
        }

        q.emplace(nx, ny);
        vis[nx][ny] = true;
      }
    }

    needed += change;
  }


  int unreachable = 0;
  rep(i, 0, n) {
    rep(j, 0, m) {
      if (!vis[i][j] && g[i][j] == '.') {
        unreachable++;
      }
    }
  }

  cout << needed << ' ' << unreachable;
}