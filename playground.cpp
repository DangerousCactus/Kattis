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
  while (cin >> n, n != 0) {
    vector<ll> rings(n);
    string ans = "NO";

    for (auto& x : rings) {
      int y;
      char c;
      cin >> x >> c >> y;
      x = 1000 * x + y;
    }

    sort(all(rings));

    while (sz(rings)) {
      if (accumulate(rings.begin(), prev(rings.end()), 0LL) >= rings.back()) {
        ans = "YES";
      }
      rings.pop_back();
    }

    cout << ans << '\n';
  }
}