#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bool board[1000][1000];
int group[1000][1000];
int r, c;

void bfs(int i, int j, int counter) {
  if (group[i][j] == 0) {
    group[i][j] = counter;

    if (i - 1 >= 0 && (board[i][j] == board[i - 1][j])) {
      bfs(i - 1, j, counter);
    }
    if (i + 1 < r && (board[i][j] == board[i + 1][j])) {
      bfs(i + 1, j, counter);
    }
    if (j - 1 >= 0 && (board[i][j] == board[i][j - 1])) {
      bfs(i, j - 1, counter);
    }
    if (j + 1 < c && (board[i][j] == board[i][j + 1])) {
      bfs(i, j + 1, counter);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;

  char d;
  rep(i, 0, r) rep(j, 0, c) {
    cin >> d;
    board[i][j] = (d == '1');
  }

  memset(group, 0, sizeof group);

  // preprocess
  int counter = 0;
  rep(i, 0, r) rep(j, 0, c) {
    if (group[i][j] == 0) {
      bfs(i, j, ++counter);
    }
  }

  int q;
  cin >> q;
  pii a, b;
  while (q--) {
    cin >> a.first >> a.second >> b.first >> b.second;

    if (group[a.first - 1][a.second - 1] != group[b.first - 1][b.second - 1])
      cout << "neither";
    else {
      if (board[a.first - 1][a.second - 1] == 0)
        cout << "binary";
      else
        cout << "decimal";
    }

    cout << '\n';
  }

  return 0;
}