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

  int n, m;
  cin >> n >> m;

  vector<vi> p(n, vi(m));

  rep(i, 0, n) {
    rep(j, 0, m) { cin >> p[i][j]; }
  }

  int best = INT_MAX;

  rep(a, 0, n) {
    rep(b, 0, m) {
      int z = 0;
      rep(i, 0, n) {
        rep(j, 0, m) { z += p[i][j] * (abs(a - i) + abs(b - j)); }
      }
      best = min(z, best);
    }
  }

  cout << best;

  return 0;
}