#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// a will be at most 125001
// a will be strictly greater than 0

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int d, s;
  cin >> d >> s;

  long double lo = 0, hi = 125001, mid;

  rep(i, 0, 10000) {
    mid = (lo + hi) / 2;
    if (mid + s < mid * cosh(d / (2 * mid))) {
      lo = mid;
    } else if (mid + s > mid * cosh(d / (2 * mid))) {
      hi = mid;
    }
  }

  cout << setprecision(15) << 2 * mid * sinh(d / (2 * mid));

  return 0;
}