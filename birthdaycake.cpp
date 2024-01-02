#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct line {
  int a, b, c;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, r;
  cin >> n >> m >> r;

  vector<pii> candles(n);
  vector<line> lines(m);

  for (auto &&x : candles)
    cin >> x.first >> x.second;

  for (auto &&x : lines)
    cin >> x.a >> x.b >> x.c;

  int segs = m + 1;

  rep(i, 0, lines.size()) {
    rep(j, i + 1, lines.size()) {
      // if the intersection lies in the circle, add two segments instead of one
      long double a, b, c, d, e, f;
      a = lines[i].a;
      b = lines[i].b;
      c = lines[i].c;

      d = lines[j].a;
      e = lines[j].b;
      f = lines[j].c;

      long double x = (c * e - b * f) / (b * d - a * e);
      long double y = (a * f - d * c) / (d * b - a * e);

      // for my sanity
      if (x * x + y * y < r * r != x * x + y * y <= r * r) {
        return 0 / 0;
      }

      if (x * x + y * y < r * r) {
        segs++;
      }
    }
  }

  set<unsigned int> t;

  for (auto &&x : candles) {
    unsigned int pog = 0;

    for (auto &&l : lines) {
      pog |= x.first * l.a + x.second * l.b + l.c > 0;
      pog <<= 1;
    }
    t.insert(pog);
  }

  cout << ((t.size() == candles.size() && candles.size() == segs) ? "yes" : "no");

  return 0;
}