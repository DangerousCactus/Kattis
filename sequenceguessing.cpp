#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1E5;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  auto getpos = [](int num) {
      return num / 3 * 2 + 1 + (num % 3 != 0);
  };

  cout << getpos(MAXN) << endl;
  set<int> nums{0, MAXN};
  set<int> usedIDs{1, getpos(MAXN)};

  int x;
  while (cin >> x) {
    if (x == -1) {
      rep(i, 0, MAXN + 1) {
        if (nums.count(i)) {
          cout << i << endl;
        } else {
          if (usedIDs.insert(getpos(i)).second) {
            cout << i << endl;
          }
        }
      }
      break;
    }

    if (x % 3 == 0) {
      cout << getpos(x) << endl;
    } else {
      if (usedIDs.insert(getpos(x)).second) {
        cout << -1 << endl;

        if (getpos(x - 1) == getpos(x)) {
          nums.insert(x - 1);
        } else if (getpos(x + 1) == getpos(x)) {
          nums.insert(x + 1);
        }
      } else {
        cout << getpos(x) << endl;
      }
    }

  }
}