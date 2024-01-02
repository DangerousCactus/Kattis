#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> nums(n);
  for (auto&& x : nums) {
    cin >> x;
  }

  bool change = false;

  rep(i, 0, n - 1) {
    if (sz(nums[i]) == sz(nums[i + 1])) {
      string t1 = nums[i], t2 = nums[i + 1];
      t1[0] = '9';

      if (t1 > t2) {
        nums[i][0] = '9';
        change = true;
        break;
      }

      t1 = nums[i];
      t2[0] = '1';

      if (t1 > t2) {
        nums[i + 1][0] = '1';
        change = true;
        break;
      }

      if (sz(nums[i]) == 1 && t1 > "0") {
        nums[i + 1] = "0";
        change = true;
        break;
      }
    }
  }

  if (!change) {
    cout << "impossible";
  } else {
    for (auto&& x : nums) {
      cout << x << ' ';
    }
  }
}