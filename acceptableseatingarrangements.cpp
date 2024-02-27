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

  int r, c;
  cin >> r >> c;

  vector<vi> board(r, vi(c)), desired(r, vi(c));
  vector<vi> out;

  auto locate = [r, c](int x, vector<vi> &g) {
      rep(i, 0, r) {
        rep(j, 0, c) {
          if (g[i][j] == x) {
            return pii{i, j};
          }
        }
      }
  };

  auto doSwap = [&](int val, int nx, int ny) {
      if (board[nx][ny] == val) {
        return;
      }

      auto [x, y] = locate(val, board);

      int last = c - 1;
      while (board[x][last] > board[nx][ny]) {
        last--;
      }

      while (last >= y) {
        out.push_back({nx, ny, x, last});
        swap(board[nx][ny], board[x][last--]);
      }
  };

  for (auto &x: board) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  for (auto &x: desired) {
    for (auto &y: x) {
      cin >> y;
    }
  }

  rep(i, 1, r * c) {
    auto [nx, ny] = locate(i, desired);
    doSwap(i, nx, ny);
  }

  cout << sz(out) << '\n';
  for (auto &x: out) {
    for (auto &y: x) {
      cout << y + 1 << ' ';
    }
    cout << '\n';
  }
}