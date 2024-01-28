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

  const string TELLITE = "TELLITE";
  const int n = sz(TELLITE);

  string out = "S";
  ll target;
  cin >> target;

  for (int z = 7; z >= 0; z--) {
    string s;
    for (int k = z; k >= 0; k--) {
      for (auto c: TELLITE) {
        rep(i, 0, 1 << k) {
          s += c;
        }
      }
    }

    vector<vector<ll>> DP(sz(s) + 1, vector<ll>(n + 1, -1));

    function<ll(int, int)> calc = [&](int i, int j) -> ll {
        auto &key = DP[i][j];
        if (key != -1) {
          return key;
        }

        key = 0;
        if (j == n) {
          return 1;
        }

        if (i == sz(s)) {
          return 0;
        }

        key += calc(i + 1, j);
        if (s[i] == TELLITE[j]) {
          key += calc(i + 1, j + 1);
        }

        return key;
    };

    ll ct = calc(0, 0);
//    cout << ct << endl;
    out += string((target / ct), 'A');

    for (auto c: TELLITE) {
      rep(i, 0, 1 << z) {
        out += c;
      }
    }
    target %= ct;
  }

  assert(sz(out) <= 5000);
  cout << out;
}