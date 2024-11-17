#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid(ll a, ll b, ll &x, ll &y) {
  if (!b)
    return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}

const ll mod = 998244353; // change to something else
struct Mod {
  ll x;
  Mod(ll xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
  Mod operator/(Mod b) { return *this * invert(b); }
  Mod invert(Mod a) {
    ll x, y, g = euclid(a.x, mod, x, y);
    assert(g == 1);
    return Mod((x + mod) % mod);
  }
  Mod operator^(ll e) {
    if (!e)
      return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, k, p;
  cin >> n >> k >> p;

  vector<Mod> fact(n + 1, Mod(0));
  fact[0] = Mod(1);
  rep(i, 1, n + 1) { fact[i] = fact[i - 1] * i; }

  if (k * p > n) {
    cout << 1;
    exit(0);
  }

  Mod num = fact[n] / fact[n - k * p];
  Mod denom = fact[n] / fact[n - p];
  denom = denom ^ k;

  num = denom - num;

  cout << (num / denom).x;
}