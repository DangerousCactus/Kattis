#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2007;
const vector<pii> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int p;
  while (cin >> p, p != 0) {
    vector<pii> a(p);
    for (auto &[x, y] : a) {
      cin >> x >> y;
    }

    cin >> p;
    vector<pii> b(p);
    for (auto &[x, y] : b) {
      cin >> x >> y;
    }

    vector<vector<bool>> aend(MAXN, vector<bool>(MAXN));
    vector<vector<bool>> vis(MAXN, vector<bool>(MAXN));

    a.push_back(a.front());
    rep(i, 0, sz(a) - 1) {
      rep(x, min(a[i].first, a[i + 1].first), max(a[i].first, a[i + 1].first) + 1) {
        rep(y, min(a[i].second, a[i + 1].second), max(a[i].second, a[i + 1].second) + 1) { aend[x][y] = true; }
      }
    }

    queue<pii> q;
    int ct = 0;
    int best = INT_MAX;

    b.push_back(b.front());
    rep(i, 0, sz(b) - 1) {
      rep(x, min(b[i].first, b[i + 1].first), max(b[i].first, b[i + 1].first) + 1) {
        rep(y, min(b[i].second, b[i + 1].second), max(b[i].second, b[i + 1].second) + 1) {
          q.emplace(x, y);
          vis[x][y] = true;
        }
      }
    }

    while (sz(q)) {
      queue<pii> nq;
      while (sz(q)) {
        auto [x, y] = q.front();
        q.pop();

        if (aend[x][y]) {
          best = min(best, ct);
          break;
        }

        for (auto &[dx, dy] : dirs) {
          int nx = x + dx, ny = y + dy;
          if (nx < 0 || ny < 0 || nx > 2000 || ny > 2000) {
            continue;
          }

          if (vis[nx][ny]) {
            continue;
          }

          nq.emplace(nx, ny);
          vis[nx][ny] = true;
        }
      }

      if (best != INT_MAX) {
        break;
      }
      q = nq;
      ct++;
    }

    cout << best << '\n';
  }
}