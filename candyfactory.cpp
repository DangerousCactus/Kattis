#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n, k;
  cin >> n >> k;

  vector<ll> nums(n);
  for (auto &x: nums) {
    cin >> x;
  }

  sort(all(nums), greater<>());

  auto solve = [&](ll bagCount) {
      ll layersLeft = k;
      ll leftThisLayer = 0;

      for (auto &x: nums) {
        if (leftThisLayer < x) {
          if (layersLeft == 0) {
            return false;
          }

          layersLeft--;
          leftThisLayer += bagCount;
        }

        leftThisLayer -= x;
      }

      return true;
  };

  ll lo = *max_element(all(nums)), hi = 1E18; // (]
  while (lo < hi) {
    ll mid = (lo + hi) / 2;

    if (solve(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  cout << -accumulate(all(nums), -hi * k);
}