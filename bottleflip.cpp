#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double gss(double a, double b, double (*f)(double)) {
  double r = (sqrt(5) - 1) / 2, eps = 1e-7;
  double x1 = b - r * (b - a), x2 = a + r * (b - a);
  double f1 = f(x1), f2 = f(x2);
  while (b - a > eps)
    if (f1 < f2) {  // change to > to find maximum
      b = x2;
      x2 = x1;
      f2 = f1;
      x1 = b - r * (b - a);
      f1 = f(x1);
    } else {
      a = x1;
      x1 = x2;
      f1 = f2;
      x2 = a + r * (b - a);
      f2 = f(x2);
    }
  return a;
}

int h, r, da, dw;
double f(double x) {
  double mw = dw * x;
  double ma = da * (h - x);
  return (x / 2 * mw + (x + (h - x) / 2) * ma) / (mw + ma);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> h >> r >> da >> dw;
  cout << fixed << setprecision(15) << gss(0, h, f);
}