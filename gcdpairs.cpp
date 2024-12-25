#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;

const int MAX_PR = 1E4 + 1;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
  isprime.set();
  isprime[0] = isprime[1] = 0;
  for (int i = 4; i < lim; i += 2)
    isprime[i] = 0;
  for (int i = 3; i * i < lim; i += 2)
    if (isprime[i])
      for (int j = i * i; j < lim; j += i * 2)
        isprime[j] = 0;
  vi pr;
  rep(i, 2, lim) if (isprime[i]) pr.push_back(i);
  return pr;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vi seen(1E6 + 6);
  ll ans = 0;

  vi primes = eratosthenesSieve(MAX_PR);

  rep(c, 0, n) {
    ll x;
    cin >> x;

    ll origx = x;

    vi factors;
    for (auto &pr : primes) {
      int ct = 0;
      while (x % pr == 0) {
        ct++;
        x /= pr;
      }

      if (ct >= 2) {
        factors.push_back(pr);
      }
    }

    if (x != 1) {
      ll s = sqrt(x);
      if (s * s == x) {
        factors.push_back(s);
      }
    }

    ll candidates = c;

    rep(i, 1, 1 << sz(factors)) {
      int temp = 1;

      rep(j, 0, sz(factors)) {
        if (i & (1 << j)) {
          temp *= factors[j];
        }
      }

      if (__builtin_popcount(i) % 2 == 1) {
        candidates -= seen[temp];
      } else {
        candidates += seen[temp];
      }

      seen[temp]++;
    }

    ans += candidates;
  }

  cout << ans;
}
