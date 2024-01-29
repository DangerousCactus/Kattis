#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k, p;
  cin >> n >> k >> p;

  set<ll> out;

  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll j = n / i;
      if (i <= k && j <= p) {
        out.insert(i);
      }

      if (i != j && j <= k && i <= p) {
        out.insert(j);
      }
    }
  }

  cout << sz(out) << '\n';
  for (auto &x: out) {
    cout << x << '\n';
  }
}