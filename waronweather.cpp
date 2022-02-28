#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double circumference = 40000;
const long double radius = circumference / (2 * acos(-1.0L));

struct point {
  long double x, y, z;

  point() {}
  point(long double x1, long double y1, long double z1) : x(x1), y(y1), z(z1) {}

  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y, a.z - b.z);
  }

  long double mag() { return sqrt(x * x + y * y + z * z); }
  long double maxDist() { return sqrt(mag() * mag() - radius * radius); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k, m;
  cin >> k >> m;
  while (k) {
    vector<point> sats(k);
    point dest;
    int total = 0;

    for (auto &&x : sats)
      cin >> x.x >> x.y >> x.z;

    rep(i, 0, m) {
      cin >> dest.x >> dest.y >> dest.z;

      for (auto &&x : sats)
        if ((x - dest).mag() <= x.maxDist()) {
          total++;
          break;
        }
    }

    cout << total << '\n';
    cin >> k >> m;
  }

  return 0;
}