#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template <class T> struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(T d) const { return P(x * d, y * d); }
  P operator/(T d) const { return P(x / d, y / d); }
  T dot(P p) const { return x * p.x + y * p.y; }
  T cross(P p) const { return x * p.y - y * p.x; }
  T cross(P a, P b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x−axis in interva l [−pi , pi ]
  double angle() const { return atan2(y, x); }
  P unit() const { return *this / dist(); } // makes d is t ()=1
  P perp() const { return P(-y, x); }       // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a ’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream &operator<<(ostream &os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  double d;
  cin >> n;

  while (n--) {
    cin >> m >> d;
    double r = d / 2;

    vector<Point<double>> pts(m);
    for (auto &&x : pts)
      cin >> x.x >> x.y;

    int best = 1;

    rep(i, 0, m) {
      rep(j, i + 1, m) {
        auto diff = (pts[i] - pts[j]);

        if (diff.dist() > d) {
          continue;
        }

        auto mid = (pts[i] + pts[j]) / 2;
        auto diffn = diff.normal();

        double offset = sqrt(r * r - (diff / 2).dist2());

        auto c1 = mid + diffn * offset;
        auto c2 = mid - diffn * offset;

        for (auto &&x : {c1, c2}) {
          int curr = 0;

          for (auto &&y : pts) {
            if ((x - y).dist() <= r) {
              curr++;
            }
          }

          best = max(best, curr);
        }
      }
    }

    cout << best << '\n';
  }
}