#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;

  vector<pair<long double, long double>> pos(n);
  vector<long double> times(n);

  rep(i, 0, n) cin >> pos[i].first >> pos[i].second >> times[i];

  // actual
  long double actual = 0;
  rep(i, 1, n) {
    actual += hypot(pos[i].first - pos[i - 1].first,
                    pos[i].second - pos[i - 1].second);
  }

  // gps
  long double gps = 0;
  int idx = 1;

  vector<pair<long double, long double>> posgps;
  posgps.push_back(pos.front());
  for (double ct = t; ct < times.back(); ct += t) {
    while (times[idx] < ct)
      idx++;

    int xdiff = pos[idx].first - pos[idx - 1].first;
    int ydiff = pos[idx].second - pos[idx - 1].second;

    long double xpos = pos[idx - 1].first +
               xdiff * ((ct - times[idx - 1]) / (times[idx] - times[idx - 1]));
    long double ypos = pos[idx - 1].second +
               ydiff * ((ct - times[idx - 1]) / (times[idx] - times[idx - 1]));

    posgps.push_back(mp(xpos, ypos));
  }
  posgps.push_back(pos.back());

  rep(i, 1, posgps.size()) {
    gps += hypot(posgps[i].first - posgps[i - 1].first,
                 posgps[i].second - posgps[i - 1].second);
  }

  cout << setprecision(18) << (actual - gps) / (actual / 100);

  return 0;
}