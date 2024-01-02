#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct hole {
  int points, row, idx;
  double currChance = 0, nextChance = 0, trc, tlc, brc, blc, fall;
};

vector<hole> holes;
double ev = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  holes.resize(n * (n + 1) / 2);

  int curr = 0;
  for (int currRow = 1; currRow <= n; currRow++) {
    rep(i, 0, currRow) {
      holes[curr].idx = curr;
      holes[curr].row = currRow;
      cin >> holes[curr++].points;
    }
  }

  for (auto&& x : holes) {
    cin >> x.tlc >> x.trc >> x.blc >> x.brc >> x.fall;
  }

  holes[0].currChance = 1;
  double prev = -1;

  rep(i, 0, 1000000) {
    for (auto&& x : holes) {
      ev += x.currChance * x.fall * x.points;
      if (x.trc) {
        holes[x.idx - x.row + 1].nextChance += x.currChance * x.trc;
      }
      if (x.tlc) {
        holes[x.idx - x.row].nextChance += x.currChance * x.tlc;
      }
      if (x.brc) {
        holes[x.idx + x.row + 1].nextChance += x.currChance * x.brc;
      }
      if (x.blc) {
        holes[x.idx + x.row].nextChance += x.currChance * x.blc;
      }
    }

    double tot = 0;
    for (auto&& x : holes) {
      x.currChance = x.nextChance;
      tot += x.currChance;
      x.nextChance = 0;
    }

    if (tot < 1E-6)
      break;
  }

  cout << setprecision(15) << ev;

  return 0;
}