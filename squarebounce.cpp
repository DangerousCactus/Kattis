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

  ll a, b, n;
  cin >> a >> b >> n;

  ll dim = a * b;

  ll currx = -dim;
  ll curry = 0;

  ll velx = b;
  ll vely = a;

  rep(i, 0, n + 1) {
    ll tv, th;

    // time to vert
    if (vely > 0) {
      tv = (dim - curry) / vely;
    } else {
      tv = (-dim - curry) / vely;
    }

    // time to horiz
    if (velx > 0) {
      th = (dim - currx) / velx;
    } else {
      th = (-dim - currx) / velx;
    }

    currx += min(tv, th) * velx;
    curry += min(tv, th) * vely;

    if (tv < th) {
      vely *= -1;
    } else if (tv > th) {
      velx *= -1;
    }
  }

  ll temp = abs(__gcd(currx, dim));
  if (currx == 0) {
    cout << "0 1 ";
  } else {
    cout << currx / temp << ' ' << dim / temp << ' ';
  }

  temp = abs(__gcd(curry, dim));
  if (curry == 0) {
    cout << "0 1 ";
  } else {
    cout << curry / temp << ' ' << dim / temp << ' ';
  }
}