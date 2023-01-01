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

  double l, k, t1, t2, h;
  cin >> l >> k >> t1 >> t2 >> h;

  cout.precision(7);
  cout.setf(ios::fixed);

  double b = -k * (t2 + t1) - h;
  double c = k * l * t1;
  double disc = sqrt(b * b - 4 * c);
  double ans1 = (-b + disc) / 2;

  // if h < l there is only one solution
  if (h < l) {
    cout << h << ' ' << h;
  } else if (h == l) {
    cout << h << ' ' << ans1;
  } else if (h > l) {
    cout << ans1 << ' ' << ans1;
  }

  return 0;
}