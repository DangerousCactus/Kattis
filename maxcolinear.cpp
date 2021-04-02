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

  vector<pair<long double, long double>> pts;  // x, y
  map<pair<long double, long double>,          // slope, yint
      pair<int, vector<pair<long double, long double>>::iterator>>
      slopes;

  int n, mx;
  long double slope;
  double yint;
  cin >> n;

  while (n != 0) {
    mx = 0;
    pts.clear();
    slopes.clear();
    pts.resize(n);

    for (auto& i : pts)
      cin >> i.first >> i.second;

    for (auto i = pts.begin() + 1; i != pts.end(); i++) {
      for (auto prev = pts.begin(); prev != i; prev++) {
        if (i->first == prev->first) {
          slope = 100000;
          yint = 100000 + i->first;
        } else {
          slope = (i->second - prev->second) / (i->first - prev->first);
          yint = i->second - i->first * slope;
        }

        auto curr = mp(slope, yint);
        if (slopes.count(curr) == 0) {
          slopes[curr] = mp(1, i);
        } else if (slopes[curr].second != i) {
          ++slopes[curr].first;
          slopes[curr].second = i;
        }
      }
    }

    for (auto i = slopes.begin(); i != slopes.end(); i++)
      mx = max(mx, i->second.first);

    cout << mx + 1 << '\n';
    cin >> n;
  }

  return 0;
}