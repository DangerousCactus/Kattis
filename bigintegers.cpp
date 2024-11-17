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

  int t;
  cin >> t;

  while (t--) {
    string a, b;
    cin >> a >> b;

    bool scomp = a < b;

    if (sz(a) != sz(b)) {
      if (a < b == sz(a) < sz(b)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    } else {
      rep(i, 0, sz(a)) {
        if (isalpha(a[i])) {
          a[i] ^= ' ';
        }
        if (isalpha(b[i])) {
          b[i] ^= ' ';
        }
      }

      if (a < b == scomp) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}