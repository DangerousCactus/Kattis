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

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    int l = 1;
    while (l * l < sz(s)) {
      l++;
    }

    vector<vector<char>> g(l, vector<char>(l, '*'));
    auto g2 = g;

    int idx = 0;
    rep(i, 0, l) {
      rep(j, 0, l) {
        if (idx < sz(s)) {
          g[i][j] = s[idx++];
        }
      }
    }

    rep(i, 0, l) {
      rep(j, 0, l) {
        g2[i][j] = g[l - 1 - j][i];
      }
    }


    for (auto &r: g2) {
      for (auto &c: r) {
        if (c != '*') {
          cout << c;
        }
      }
    }

    cout << '\n';
  }
}