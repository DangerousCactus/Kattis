#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<ll>> adj(n);
  ll ct = 0;

  rep(i, 0, n - 1) {
    int u, v, p;
    cin >> u >> v >> p;
    adj[u].push_back(p);
    adj[v].push_back(p);
  }

  for (auto &x: adj) {
    ll y = *max_element(all(x));
    ll total = accumulate(all(x), 0LL);

    if (y > total - y) {
      ct += 2 * y - total;
    } else {
      ct += total % 2;
    }

  }

  cout << ct / 2;
  return 0;
}