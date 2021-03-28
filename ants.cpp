#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int q, in;
  int l, n;
  cin >> q;

  while (q--) {
    cin >> l >> n;
    int mn = 0, mx = 0;

    rep(i, 0, n) {
      cin >> in;

      mn = max(mn, min(in, l - in));
      mx = max(mx, max(in, l - in));
    }

    cout << mn << ' ' << mx << '\n';
  }
  return 0;
}