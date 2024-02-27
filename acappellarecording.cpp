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

  int n, d;
  cin >> n >> d;

  vi nums(n);
  for (auto &x: nums) {
    cin >> x;
  }

  sort(all(nums));

  auto it = nums.begin();
  int ct = 0;
  while (it != nums.end()) {
    it = upper_bound(all(nums), *it + d);
    ct++;
  }
  cout << ct;
}