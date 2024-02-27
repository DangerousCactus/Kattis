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
  vi out;

  for (auto &x: nums) {
    cin >> x;
  }

  rep(k, 2, n + 1) {
    if (n % k != 0) {
      continue;
    }

    int nk = n / k;

    bool possible = true;

    rep(i, 0, k - 1){
      auto it = nums.begin() + i * (n / k);
      possible = possible && (*max_element(it, it + nk) < *min_element(it + nk, it + 2 * nk));
    }

    if(possible){
      out.push_back(k);
    }
  }

  if (!sz(out)) {
    out.push_back(-1);
  }

  for (auto &x: out) {
    cout << x << '\n';
  }
}