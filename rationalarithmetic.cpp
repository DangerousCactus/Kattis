#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll x1, y1, x2, y2, num, denom, g;
  char op;

  int n;
  cin >> n;

  while (n--) {
    cin >> x1 >> y1 >> op >> x2 >> y2;

    if (op == '+') {
      num = x1 * y2 + x2 * y1;
      denom = y1 * y2;

    } else if (op == '-') {
      num = x1 * y2 - x2 * y1;
      denom = y1 * y2;

    } else if (op == '*') {
      num = x1 * x2;
      denom = y1 * y2;

    } else if (op == '/') {
      num = x1 * y2;
      denom = y1 * x2;
    }

    if (num > 0 && denom < 0 || num < 0 && denom > 0) {
      cout << '-';
    }
    num = abs(num);
    denom = abs(denom);
    g = __gcd(num, denom);
    cout << abs(num) / g  << " / " << abs(denom) / g << '\n';
  }

  return 0;
}