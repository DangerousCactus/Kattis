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

  string s;
  cin >> s;

  vi out;

  rep(k, 1, 2007) {
    int at = 0, bt = 0, a = 0, b = 0;

    for (auto i = s.begin(); i != s.end(); i++) {
      if (*i == 'A') {
        a++;
      } else {
        b++;
      }

      if (a == k) {
        at++;
        a = 0, b = 0;
      }
      if (b == k) {
        bt++;
        a = 0, b = 0;
      }
    }

    if (at > bt)
      out.push_back(k);
  }

  cout << sz(out) << endl;
  for (auto &&x : out)
    cout << x << ' ';
}