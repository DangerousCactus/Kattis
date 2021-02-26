#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define rdi(x) \
  int x;       \
  cin >> x;
#define rdrp(x) \
  rdi(x);       \
  for (; x > 0; x--)
#define pb(x)    push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

struct point {
  int r, c, l;
  point() : r(0), c(0), l(0) {}
  point(int a, int b, int d) : r(a), c(b), l(d) {}
  bool operator==(const point& p) { return p.r == r && p.c == c && p.l == l; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int L, R, C;
  char t;
  cin >> L >> R >> C;
  point start, end;

  while (L != 0) {
    bool d[R][C][L];
    bool vis[R][C][L];
    memset(d, false, sizeof d);
    memset(vis, false, sizeof vis);

    rep(l, 0, L) {
      rep(r, 0, R) {
        rep(c, 0, C) {
          cin >> t;
          if (t != '#')
            d[r][c][l] = true;
          else {
            vis[r][c][l] = true;
          }

          if (t == 'S') {
            start = point(r, c, l);
          } else if (t == 'E') {
            end = point(r, c, l);
          }
        }
      }
    }

    queue<point> q;
    q.push(start);
    bool found = false;
    int iter = -1;
    while (!found && !q.empty()) {
      queue<point> nextq;

      while (!q.empty()) {
        point t = q.front();
        q.pop();
        vis[t.r][t.c][t.l] = true;

        if (t == end) {
          found = true;
        }

        if (t.c > 0 && !vis[t.r][t.c - 1][t.l]) {
          nextq.push(point(t.r, t.c - 1, t.l));
          vis[t.r][t.c - 1][t.l] = true;
        }
        if (t.c < C - 1 && !vis[t.r][t.c + 1][t.l]) {
          nextq.push(point(t.r, t.c + 1, t.l));
          vis[t.r][t.c + 1][t.l] = true;
        }
        if (t.r > 0 && !vis[t.r - 1][t.c][t.l]) {
          nextq.push(point(t.r - 1, t.c, t.l));
          vis[t.r - 1][t.c][t.l] = true;
        }
        if (t.r < R - 1 && !vis[t.r + 1][t.c][t.l]) {
          nextq.push(point(t.r + 1, t.c, t.l));
          vis[t.r + 1][t.c][t.l] = true;
        }
        if (t.l > 0 && !vis[t.r][t.c][t.l - 1]) {
          nextq.push(point(t.r, t.c, t.l - 1));
          vis[t.r][t.c][t.l - 1] = true;
        }
        if (t.l < L - 1 && !vis[t.r][t.c][t.l + 1]) {
          nextq.push(point(t.r, t.c, t.l + 1));
          vis[t.r][t.c][t.l + 1] = true;
        }
      }

      iter++;
      q = nextq;
    }

    if (!found) {
      cout << "Trapped!\n";
    } else {
      cout << "Escaped in " << iter << " minute(s).\n";
    }

    cin >> L >> R >> C;
  }

  return 0;
}