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

  int k, n;
  cin >> k;

  set<int> out;

  rep(z, 1, k + 1) {
    cin >> n;
    vi p(n);
    for (auto &&x : p)
      cin >> x;

    set<int> left, right;
    left.insert(p[0]);
    rep(i, 1, n) right.insert(p[i]);

    rep(i, 1, n - 1) {
      int curr = p[i];

      auto l = left.upper_bound(curr);
      if (l != left.end()) {
        auto r = right.upper_bound(*l);
        if (r != right.end()) {
          out.insert(z);
        }
      }

      left.insert(curr);
      right.erase(curr);
    }
  }

  cout << sz(out) << endl;
  for (auto &&x : out)
    cout << x << endl;

  return 0;
}