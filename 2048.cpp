#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int in;
  int board[4][4] = {0};
  int newBoard[4][4] = {0};

  rep(y, 0, 4) {
    rep(x, 0, 4) {
      cin >> in;
      board[x][y] = in;
    }
  }

  int dir;
  cin >> dir;

  if (dir == 0) {
    rep(y, 0, 4) {
      int cx = 0;
      rep(x, 0, 4) {
        if (x < 3 && board[x][y] == board[x + 1][y]) {
          newBoard[cx][y] == 2 * board[x][y];
          x++;
        } else {
          newBoard[cx][y] == board[x][y];
        }
        cx++;
      }
      while (cx++ < 4) {
        newBoard[cx++][y] = 0;
      }
    }
  } else if (dir == 3) {
    rep(y, 0, 4) {
      int cx = 3;
      rep(x, 0, 4) {
        if (x < 3 && board[3 - x][y] == board[2 - x][y]) {
          newBoard[cx][y] == 2 * board[x][y];
          x--;
        } else {
          newBoard[cx][y] == board[x][y];
        }
        cx--;
      }
      while (cx-- >= 0) {
        newBoard[cx][y] = 0;
      }
    }
  } else if (dir == 4) {
    rep(x, 0, 4) {
      int cy = 0;
      rep(y, 0, 4) {
        if (y < 3 && board[x][y] == board[x][y + 1]) {
          newBoard[x][cy] == 2 * board[x][y];
          y++;
        } else {
          newBoard[x][cy] == board[x][y];
        }
        cy++;
      }
      while (cy++ < 4) {
        newBoard[x][cy] = 0;
      }
    }
  } else if (dir == 2) {
    rep(x, 0, 4) {
      int cy = 3;
      rep(y, 0, 4) {
        if (y < 3 && board[x][3 - y] == board[x][2 - y]) {
          newBoard[x][cy] == 2 * board[x][y];
          y--;
        } else {
          newBoard[x][cy] == board[x][y];
        }
        cy--;
      }
      while (cy-- >= 0) {
        newBoard[x][cy] = 0;
      }
    }
  }

  rep(x, 0, 4) {
    rep(y, 0, 4) {
      cout << newBoard[x][y];
      if (y != 3)
        cout << ' ';
    }
    cout << "\n";
  }

  return 0;
}