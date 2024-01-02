#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

bool board[10001][10001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  memset(board, false, sizeof board);

  int numGoblins;
  cin >> numGoblins;
  int count = numGoblins;
  pair<int, int> goblins[numGoblins];

  rep(g, 0, numGoblins) { cin >> goblins[g].first >> goblins[g].second; }

  int numSprinklers;
  cin >> numSprinklers;

  rep(s, 0, numSprinklers) {
    int sx, sy, sr;
    cin >> sx >> sy >> sr;

    rep(x, max(0, sx - sr), min(10001, sx + sr + 1))
        rep(y, max(0, sy - sr), min(10001, sy + sr + 1)) {
      if (pow(x - sx, 2) + pow(y - sy, 2) <= pow(sr, 2))
        board[x][y] = true;
    }
  }

  for (auto g : goblins)
    if (board[g.first][g.second])
      count--;

  cout << count;
  return 0;
}
