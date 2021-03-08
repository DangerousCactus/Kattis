#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, l, w;
  while (cin >> n >> l >> w) {
    deque<pair<long double, long double>> ranges;

    rep(i, 0, n) {
      int x, r;
      cin >> x >> r;

      if (2 * r <= w)
        continue;

      long double delta = sqrt(pow(r, 2) - pow(w * 0.5L, 2));
      ranges.pb(mp(x - delta, x + delta));
    }

    sort(ranges.begin(), ranges.end());
    int total = 0;
    long double xsofar = 0;

    while (xsofar < l && !ranges.empty()) {
      long double best = 0;

      while (!ranges.empty() && ranges.front().first <= xsofar) {
        best = max(best, ranges.front().second);
        ranges.pop_front();
      }

      if (best == 0) {
        break;
      } else {
        total++;
        xsofar = best;
      }
    }

    if (xsofar < l) {
      cout << -1 << endl;
    } else {
      cout << total << endl;
    }
  }

  return 0;
}