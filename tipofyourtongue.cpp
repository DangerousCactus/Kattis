#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef uint64_t ull;

struct H {
    ull x;

    H(ull x = 0) : x(x) {}

    H operator+(H o) { return x + o.x + (x + o.x < x); }

    H operator-(H o) { return *this + ~o.x; }

    H operator*(H o) {
      auto m = (__uint128_t) x * o.x;
      return H((ull) m) + (ull) (m >> 64);
    }

    ull get() const { return x + !~x; }

    bool operator==(H o) const { return get() == o.get(); }

    bool operator<(H o) const { return get() < o.get(); }
};

static const H C = (ll) 1e11 + 3; // (order ~ 3e9; random also ok)

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  unordered_map<ull, int> m, pref, suff;

  vector<string> d(n);
  for (auto &x : d) {
    cin >> x;

    H h{};
    rep(i, 0, sz(x)) {
      h = h * C + x[i];
      h = h * C + x[sz(x) - 1 - i];
      m[h.x]++;
    }

    h = {};
    rep(i, 0, sz(x)) {
      h = h * C + x[i];
      pref[h.x]++;
    }

    h = {};
    rep(i, 0, sz(x)) {
      h = h * C + x[sz(x) - 1 - i];
      suff[h.x]++;
    }
  }

  while (q--) {
    string type, a, b;
    cin >> type >> a >> b;

    H AND{}, A{}, B{};
    rep(i, 0, sz(a)) {
      AND = AND * C + a[i];
      AND = AND * C + b[sz(a) - 1 - i];
    }

    rep(i, 0, sz(a)) {
      A = A * C + a[i];
    }

    rep(i, 0, sz(a)) {
      B = B * C + b[sz(a) - 1 - i];
    }

    if (type == "AND") {
      cout << m[AND.x];
    } else if (type == "OR") {
      cout << pref[A.x] + suff[B.x] - m[AND.x];
    } else if (type == "XOR") {
      cout << pref[A.x] + suff[B.x] - 2 * m[AND.x];
    }

    cout << '\n';
  }


}