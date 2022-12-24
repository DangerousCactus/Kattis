#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s, m;
  cin >> n >> s >> m;

  vi board(n);

  for (auto &&x : board)
    cin >> x;

  board.insert(board.begin(), 0);

  set<int> vis;

  int h = 0;
  while (true) {
    vis.insert(s);

    if (board[s] == m) {
      cout << "magic ";
      break;
    }
    h++;

    s += board[s];

    if (s <= 0) {
      cout << "left ";
      break;
    }

    if (s > n) {
      cout << "right ";
      break;
    }

    if(!vis.insert(s).second){
      cout << "cycle ";
      break;
    }
  }

  cout << endl << h;

  return 0;
}