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

  int n, x, y;
  cin >> n >> x >> y;

  int f = 0, b = 0, fb = 0;

  rep(i, 1, n + 1) {
    if (i % x == 0 && i % y == 0) {
      fb++;
    } else if (i % x == 0) {
      f++;
    } else if (i % y == 0) {
      b++;
    }
  }

  cout << f << ' ' << b << ' ' << fb;
}