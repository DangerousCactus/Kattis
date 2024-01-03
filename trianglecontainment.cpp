#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {
    for (; pos < sz(s); pos |= pos + 1)
      s[pos] += dif;
  }
  ll query(int pos) {
    ll res = 0;
    for (; pos > 0; pos &= pos - 1)
      res += s[pos - 1];
    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x;
  cin >> n >> x;

  vector<vi> p(n, vi(3));  // x, y, v

  for (auto& x : p) {
    for (auto& y : x) {
      cin >> y;
    }
  }

  vi pts(n);
  iota(all(pts), 0);
  vi ptsr = pts;

  auto angle = [&](int i, long double z = 0) {
    return atan2(p[i][1], p[i][0] - z);
  };

  sort(pts.rbegin(), pts.rend(),
       [&](int i, int j) { return angle(i) > angle(j); });

  sort(ptsr.rbegin(), ptsr.rend(),
       [&](int i, int j) { return angle(i, x) > angle(j, x); });

  FT ft(n);
  vi toIdx(n);  // orig index to ptsr

  rep(i, 0, n) {
    toIdx[ptsr[i]] = i;
  }

  vector<ll> out(n);

  rep(i, 0, n) {
    int c = pts[i];
    out[c] = ft.query(n) - ft.query(toIdx[c]);
    ft.update(toIdx[c], p[c][2]);
  }

  for (auto& x : out) {
    cout << x << '\n';
  }
}