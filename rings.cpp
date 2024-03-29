#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

template <class T>
int sgn(T x) {
  return (x > 0) - (x < 0);
}
template <class T>
struct Point {
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
  P unit() const { return *this / dist(); }  // makes d is t ()=1
  P perp() const { return P(-y, x); }        // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated ’a ’ radians ccw around the origin
  P rotate(double a) const {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

typedef Point<double> P;
bool circleInter(P a, P b, double r1, double r2, pair<P, P>* out) {
  if (a == b) {
    assert(r1 != r2);
    return false;
  }
  P vec = b - a;
  double d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2,
         p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 || dif * dif > d2)
    return false;
  P mid = a + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  *out = {mid + per, mid - per};
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;

  while (cin >> n, n != -1) {
    vector<pair<P, double>> rings(n);
    for (auto& x : rings) {
      cin >> x.first.x >> x.first.y >> x.second;
    }

    UF uf(n);
    rep(i, 0, n) {
      rep(j, i + 1, n) {
        pair<P, P> out;
        if (circleInter(rings[i].first, rings[j].first, rings[i].second,
                        rings[j].second, &out)) {
          uf.join(i, j);
        }
      }
    }

    int out = 0;
    rep(i, 0, n) {
      out = max(out, uf.size(i));
    }

    cout << "The largest component contains " << out << " ring";
    if (out != 1)
      cout << 's';
    cout << "." << '\n';
  }
}