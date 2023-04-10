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

  ll x;
  while (cin >> x) {

    int ans = 0;
    ll curr = x;

    while (curr) {
      while (curr % 10 == 1) {
        curr /= 10;
        ans++;
      }

      if (!curr)
        break;

      curr += x;
    }

    cout << ans << endl;
  }
}