#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 15;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vi times(n);
  for (auto &x: times) {
    cin >> x;
  }
  sort(all(times));

  unordered_map<int, int> m;

  function<int(int)> solve = [&](int b) {
      if (__builtin_popcount(b) == n - 1) {
        return 0;
      }

      if (m.count(b)) {
        return m[b];
      }

      auto &best = m[b] = INT_MAX / 2;

      rep(i, 0, n) {
        rep(j, 0, n) {
          if (!(b & (1 << i)) && !(b & (1 << j))) {
            rep(k, 0, n) {
              if ((b ^ (1 << i) ^ (1 << j)) & (1 << k)) {
                best = min(best, solve(b ^ (1 << i) ^ (1 << j) ^ (1 << k)) + max(times[i], times[j]) + times[k]);
                break;
              }
            }
          }
        }
      }
      return best;
  };

  cout << solve(0) - *min_element(all(times));
}