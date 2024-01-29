#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vi nums(2 * n * k);
  for (auto &x: nums) {
    cin >> x;
  }

  if (sz(nums) == 0) {
    cout << 0;
    exit(0);
  }

  sort(all(nums));

  int lo = 0, hi = INT_MAX / 2;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    bool possible = true;

    int ct = 0; // should hit n
    // k batteries per cell
    rep(i, 0, sz(nums) - 1) {
      if (nums[i + 1] - nums[i] <= mid) {
        ct++;
        i++;
      } else if (i == 2 * ct * k) {
        possible = false;
      }
    }

    if (possible && ct >= n) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo;
}