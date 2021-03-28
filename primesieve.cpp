#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

bitset<100000007> pr;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, x;
  int nonprimes = 1;
  cin >> n >> q;

  pr[0] = pr[1] = 1;

  rep(i, 2, sqrt(n) + 1) {
    if (pr[i] == 1)
      continue;

    for (int j = 2 * i; j <= n; j += i) {
      if (pr[j] != 1)
        ++nonprimes;
      pr[j] = 1;
    }
  }

  cout << (n - nonprimes) << '\n';
  while (q--) {
    cin >> x;
    cout << !pr[x] << '\n';
  }

  return 0;
}