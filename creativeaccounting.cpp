#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi nums(90000, 0);

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, l, h;
  cin >> n >> l >> h;

  rep(i, 0, n) { cin >> nums[i]; }

  partial_sum(all(nums), nums.begin());

  int mx = 0;
  int mn = INT_MAX;

  rep(i, l, h + 1) {
    rep(j, 0, i) {
      int profit = 0;
      int idx = 0;

      profit += nums[j] > 0;
      idx += j;

      while (idx < n) {
        profit += (nums[idx + i] - nums[idx]) > 0;
        idx += i;
      }

      mn = min(mn, profit);
      mx = max(mx, profit);
    }
  }

  cout << mn << ' ' << mx;
}