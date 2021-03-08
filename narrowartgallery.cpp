#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)

using namespace std;

typedef long long ll;

int board[203][2];
int DP[203][203][3];  // if next is blocked : 0: empty. 1: left, 2: right
int n, k;

int maxm(int end, int needed, int next) {
  if (end < 0 || needed < 0 || needed > end + 1)
    return INT_MIN;

  if (DP[end][needed][next] == INT_MAX) {
    if (end == 0) {
      if (needed == 0) {
        DP[end][needed][next] = board[0][0] + board[0][1];
      } else {
        if (next == 0) {
          DP[end][needed][next] = max(board[0][0], board[0][1]);
        } else if (next == 1) {
          DP[end][needed][next] = board[0][1];
        } else if (next == 2) {
          DP[end][needed][next] = board[0][0];
        }
      }

    } else {
      DP[end][needed][next] =
          maxm(end - 1, needed, 0) + board[end][0] + board[end][1];

      if (next != 2) {
        DP[end][needed][next] =
            max(DP[end][needed][next],
                maxm(end - 1, needed - 1, 1) + board[end][1]);
      }

      if (next != 1) {
        DP[end][needed][next] =
            max(DP[end][needed][next],
                maxm(end - 1, needed - 1, 2) + board[end][0]);
      }
    }
  }

  return DP[end][needed][next];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  while (n != 0) {
    rep(i, 0, n) cin >> board[i][0] >> board[i][1];

    rep(i, 0, n) rep(j, 0, n + 1) rep(l, 0, 3) DP[i][j][l] = INT_MAX;
    cout << maxm(n - 1, k, 0) << '\n';
    cin >> n >> k;
  }

  return 0;
}