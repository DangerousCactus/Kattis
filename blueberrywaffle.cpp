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

  int r, f;
  cin >> r >> f;

  double a = 180 * f / r; // how many degrees

  while (a > 360)
    a -= 360;

  if (a < 90 || a > 270)
    cout << "up";
  else
    cout << "down";

  return 0;
}