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

  int n;
  cin >> n;

  vi nums(n);
  for (auto &x : nums) {
    cin >> x;
  }

  auto it = unique(all(nums));
  nums.erase(it, nums.end());

  n = nums.size();

  vector<vi> DP(n + 1, vi(n + 1, -1));

  function<int(int, int)> solve = [&](int a, int b) -> int {
    int &ans = DP[a][b];

    if (a >= b) {
      return (ans = 0);
    }

    if (ans != -1) {
      return ans;
    }

    ans = 1 + solve(a + 1, b);

    for (int i = a + 1; i < b; i++) {
      if (nums[i] == nums[a]) {
        ans = min(ans, solve(a, i) + solve(i + 1, b));
      }
    }

    return ans;
  };

  cout << solve(0, n);
}