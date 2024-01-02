#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  // start with number of Rs
  vi path;

  char c, last;
  cin >> c;

  bool R = (c == 'R');

  last = c;
  int count = 1;

  // group Ls and Rs
  rep(i, 1, n - 1) {
    cin >> c;
    if (c == last) {
      count++;
    } else {
      path.pb(count);
      count = 1;
      last = c;
    }
  }
  path.pb(count);
  path.pb(0);

  // starting position
  int curr = 1;
  if (!R)
    curr += path[0];

  int farthest = curr;
  cout << curr << '\n';

  rep(i, 0, path.size()) {
    if (path[i] == 0)
      break;

    if (R) {
      rep(j, 0, path[i] - 1) {
        curr += 1;
        cout << curr << '\n';
      }
      curr += path[i + 1] + 1;
      cout << curr << '\n';
      farthest = curr;

    } else {
      rep(j, 0, path[i]) {
        curr -= 1;
        cout << curr << '\n';
      }
      curr = farthest;
    }

    R = !R;
  }

  return 0;
}