#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, ld>> logs(m);

  for (auto &[t, p]: logs) {
    cin >> t >> p;
  }

  ld cost = 0;

  rep(i, 0, n) { // how much additional expected time?
    ld best = 1E31;

    for (auto &[t, p]: logs) {
      ld temp = 0;
      ld pw = 1 - p;

      rep(j, 0, 100) {
          temp += pw * ((cost + k + t) * j + t);
          pw *= p;
      }

      best = min(best, temp);
    }

    cost += best;
  }

  cout << setprecision(20) << cost;

  return 0;
}