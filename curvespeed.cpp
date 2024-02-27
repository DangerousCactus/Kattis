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

  int r;
  double s;
  while (cin >> r >> s) {
    double out = sqrt((r * (s + .16)) / .067);
    cout << round(out) << '\n';
  }
}