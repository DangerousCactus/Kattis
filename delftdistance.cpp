#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef tuple<double, int, int> tt;

map<pii, vector<pii>> dirs;

const double PI = acos(-1);
const double INF = 1E8;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  dirs[{-1, 0}] = {{-1, -1}, {-1, 1}};
  dirs[{1, 0}] = {{1, -1}, {1, 1}};
  dirs[{0, -1}] = {{-1, -1}, {1, -1}};
  dirs[{0, 1}] = {{-1, 1}, {1, 1}};

  int h, w;
  cin >> h >> w;

  vector<string> g(h);
  for (auto& x : g) {
    cin >> x;
  }

  vector<vector<double>> dist(2 * h + 1, vector<double>(2 * w + 1, INF));
  priority_queue<tt, vector<tt>, greater<>> pq;  // cost, x, y

  pq.emplace(0, 0, 0);

  while (sz(pq)) {
    auto [c, x, y] = pq.top();
    pq.pop();

    // cout << "processing " << x << ' ' << y << endl;

    if (x == 2 * h && y == 2 * w) {
      cout << fixed << setprecision(15) << c;
      exit(0);
    }

    if (dist[x][y] < c) {
      continue;
    }

    for (auto& [k, v] : dirs) {
      auto [dx, dy] = k;

      int nx = x + dx;
      int ny = y + dy;

      if (nx < 0 || ny < 0 || nx > 2 * h || ny > 2 * w ||
          (nx % 2 == 1 && ny % 2 == 1)) {
        continue;
      }

      if (dist[nx][ny] > c + 5) {
        dist[nx][ny] = c + 5;
        pq.emplace(c + 5, nx, ny);
      }
    }

    for (auto& [k, v] : dirs) {
      auto [dx, dy] = k;

      int cx = x + dx;
      int cy = y + dy;

      if (cx % 2 == 0 || cy % 2 == 0) {
        continue;
      }

      if (cx < 0 || cy < 0 || cx >= 2 * h || cy >= 2 * w) {
        continue;
      }

      if (g[cx / 2][cy / 2] == 'X') {
        continue;
      }

      for (auto& [dx2, dy2] : v) {
        auto nx = x + dx2;
        auto ny = y + dy2;

        if (nx < 0 || ny < 0 || nx > 2 * h || ny > 2 * w ||
            (nx % 2 == 1 && ny % 2 == 1)) {
          continue;
        }

        if (dist[nx][ny] > c + 2.5 * PI) {
          dist[nx][ny] = c + 2.5 * PI;
          pq.emplace(c + 2.5 * PI, nx, ny);
        }
      }
    }
  }
}