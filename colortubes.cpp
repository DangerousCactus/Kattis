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

  int n;
  cin >> n;

  vector<vi> tubes(n + 1, vi(3));
  vi tubeidx(n + 1);
  iota(all(tubeidx), 0);

  for (auto &tube : tubes) {
    for (auto &ball : tube) {
      cin >> ball;
    }
    while (sz(tube) && tube.back() == 0) {
      tube.pop_back();
    }
  }

  vector<pii> out;

  auto moveBall = [&](int from, int to) {
    tubes[to].push_back(tubes[from].back());
    tubes[from].pop_back();
    out.emplace_back(tubeidx[from], tubeidx[to]);
  };

  rep(i, 1, n + 1) {
    while (sz(tubes[0]) && sz(tubes[i]) < 3) {
      moveBall(0, i);
    }
  }

  rep(i, 1, n + 1) {
    if (tubes[i][1] != tubes[i][0]) {
      rep(j, i + 1, n + 1) {
        if (count(all(tubes[j]), tubes[i][0]) != 0) {
          if (tubes[j][0] == tubes[i][0]) {
            reverse(all(tubes[j]));
            rep(k, 0, 3) { out.emplace_back(tubeidx[j], tubeidx[0]); }
            swap(tubeidx[0], tubeidx[j]);
          }

          moveBall(i, 0);
          moveBall(i, 0);

          if (tubes[j].back() != tubes[i][0]) {
            moveBall(j, 0);
          }
          moveBall(j, i);
          moveBall(0, i);

          while (sz(tubes[0])) {
            moveBall(0, j);
          }
          break;
        }
      }
    }

    if (tubes[i][2] != tubes[i][0]) {
      rep(j, i + 1, n + 1) {
        if (count(all(tubes[j]), tubes[i][0]) != 0) {
          if (tubes[j][0] == tubes[i][0]) {
            reverse(all(tubes[j]));
            rep(k, 0, 3) { out.emplace_back(tubeidx[j], tubeidx[0]); }
            swap(tubeidx[0], tubeidx[j]);
          }

          moveBall(i, 0);

          if (tubes[j].back() != tubes[i][0]) {
            moveBall(j, 0);
          }
          moveBall(j, i);

          while (sz(tubes[0])) {
            moveBall(0, j);
          }
          break;
        }
      }
    }
  }

  cout << sz(out) << '\n';
  for (auto &[f, s] : out) {
    cout << f + 1 << ' ' << s + 1 << '\n';
  }
}