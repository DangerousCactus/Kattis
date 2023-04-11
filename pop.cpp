#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> struct Point3D {
  typedef Point3D P;
  typedef const P &R;
  T x, y, z;
  explicit Point3D(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) {}
  bool operator<(R p) const { return tie(x, y, z) < tie(p.x, p.y, p.z); }
  bool operator==(R p) const { return tie(x, y, z) == tie(p.x, p.y, p.z); }
  P operator+(R p) const { return P(x + p.x, y + p.y, z + p.z); }
  P operator-(R p) const { return P(x - p.x, y - p.y, z - p.z); }
  P operator*(T d) const { return P(x * d, y * d, z * d); }
  P operator/(T d) const { return P(x / d, y / d, z / d); }
  T dot(R p) const { return x * p.x + y * p.y + z * p.z; }
  P cross(R p) const {
    return P(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
  }
  T dist2() const { return x * x + y * y + z * z; }
  double dist() const { return sqrt((double)dist2()); }
  // Azimuthal angle ( longitude ) to x−axis in interva l [−pi , pi ]
  double phi() const { return atan2(y, x); }
  // Zenith angle ( la t i tude ) to the z−axis in interva l [0 , pi ]
  double theta() const { return atan2(sqrt(x * x + y * y), z); }
  P unit() const { return *this / (T)dist(); } // makes d is t ()=1
  // returns unit vector normal to ∗th is and p
  P normal(P p) const { return cross(p).unit(); }
  // returns point rotated ’ angle ’ radians ccw around axis
  P rotate(double angle, P axis) const {
    double s = sin(angle), c = cos(angle);
    P u = axis.unit();
    return u * dot(u) * (1 - c) + (*this) * c - cross(u) * s;
  }
};

long double EPS = 1E-3;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t, n, m;

  while (cin >> n) {
    if (n == 0)
      break;

    vector<pair<Point3D<long double>, long double>> v(n);
    vector<bool> vis(n);

    for (auto &&x : v) {
      cin >> x.second >> x.first.z >> x.first.x >> x.first.y;
      x.first.z += x.second;
    }

    cin >> m;

    while (m--) {
      Point3D<long double> A, V;
      cin >> A.x >> A.y >> A.z >> V.x >> V.y >> V.z;

      int pts = 0;

      rep(i, 0, n) {
        if (vis[i])
          continue;

        auto b = v[i];

        Point3D<long double> AB = b.first - A;
        if (AB.unit().dot(V.unit()) < 0) {
          continue;
        }
        Point3D<long double> AC = V.unit() * AB.dot(V.unit());
        Point3D<long double> BC = AB - AC;

        if (BC.dist2() <= b.second * b.second + EPS) {
          pts++;
          vis[i] = true;
        }
      }

      cout << pts << endl;
    }
  }

  return 0;
}