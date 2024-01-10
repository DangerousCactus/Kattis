#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<ll, ll> cache;

const ll mod = 1E9 + 7;

ll binpow(ll x) {
  if (cache.count(x)) {
    return cache[x];
  }

  ll ans = (binpow(x / 2) * binpow(x / 2)) % mod;

  if (x % 2) {
    ans *= cache[1];
  }

  return cache[x] = ans % mod;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;

  cache[0] = 1;
  cache[1] = 9;

  while (t--) {
    ll d;
    cin >> d;

    ll out = 8;
    cout << (out * binpow(d - 1)) % mod << endl;
  }
}