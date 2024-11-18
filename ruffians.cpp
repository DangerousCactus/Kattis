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
    vector<vi> nums(2, vi(5));
    for (auto &x : nums) {
      for (auto &y : x) {
        cin >> y;
      }
    }

    bool found = false;
    rep(i, 0, 2) {
      rep(j, 0, 5) {
        rep(a, 0, 2) {
          rep(b, 0, 5) {
            if (a != i && b != j && nums[i][j] == nums[a][b]) {
              found = true;
            }
          }
        }
      }
    }

    cout << (found ? "YES\n" : "NO\n");
  }
}