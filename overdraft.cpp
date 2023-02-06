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

  int n, c, t = 0;
  cin >> n;

  int lowest = INT_MAX;

  rep(i, 0, n) {
    cin >> c;
    t += c;

    lowest = min(lowest, t);
  }

  if (lowest >= 0)
    cout << 0;
  else
    cout << -lowest;

  return 0;
}