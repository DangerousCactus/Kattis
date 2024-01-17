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

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi nums;

    rep(i, 1, n + 1) {
      string s;
      int x;
      cin >> s >> x;
      nums.push_back(x);
    }

    sort(all(nums));

    ll out = 0;

    rep(i, 0, n) {
      out += abs(nums[i] - (i + 1));
    }

    cout << out << '\n';
  }
}