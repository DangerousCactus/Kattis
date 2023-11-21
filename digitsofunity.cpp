#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int LIM = 5000007;
const ll mod = 998244353;

ll euclid(ll a, ll b, ll& x, ll& y) {
  if (!b)
    return x = 1, y = 0, a;
  ll d = euclid(b, a % b, y, x);
  return y -= a / b * x, d;
}

struct Mod {
  ll x;
  Mod() : x(0) {}
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

Mod fact[LIM], inv[LIM];

Mod nck(int n, int k) {
  if (k > n) {
    return Mod(0);
  }

  return Mod(fact[n]) * Mod(inv[k]) * Mod(inv[n - k]);
}

// how many numbers are LE mx and have mask set
int countpos(int mask, int mx) {
  int total = 0;
  int k = (31 - __builtin_clz(mx));

  while (k >= 0) {
    if ((mx & (1 << k)) < (mask & (1 << k))) {
      break;
    }

    if ((mx & (1 << k)) > (mask & (1 << k))) {
      total += pow(2, k - __builtin_popcount(mask));
    }

    mask &= ~(1 << k);
    mx &= ~(1 << k);
    k--;
  }

  return total + (k == -1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  fact[1] = 1;
  rep(i, 2, LIM) {
    fact[i] = fact[i - 1] * i;
  }

  inv[LIM - 1] = Mod(1) / fact[LIM - 1];
  for (int i = LIM - 2; i >= 0; i--) {
    inv[i] = Mod(i + 1) * inv[i + 1];
  }

  // rep(msk, 1, 100001) {
  //   int temp = 0;
  //   rep(i, 1, 100001) {
  //     temp += ((msk & i) == msk);
  //   }
  //   int temp2 = countpos(msk, 100000);
  //   assert(temp == temp2);
  // }

  int n, k, m;  // students, bits, max
  cin >> n >> k >> m;

  Mod total(0);

  Mod oc[32];
  rep(i, k, 25) {
    int mul = 1;
    rep(j, i, 25) {
      oc[j] = oc[j] + (nck(j, i) * mul);
      mul *= -1;
    }
  }

  rep(i, 1, m + 1) {
    int ones = __builtin_popcount(i);
    if (ones >= k) {
      Mod val(nck(countpos(i, m), n));
      total = total + (val * oc[ones]);
    }
  }

  cout << (Mod(mod) + (total * fact[n])).x;
}