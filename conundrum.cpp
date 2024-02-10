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

  int ans = 0;
  rep(i, 0, sz(s) / 3) {
    ans += s[3 * i] != 'P';
    ans += s[3 * i + 1] != 'E';
    ans += s[3 * i + 2] != 'R';
  }

  cout << ans;
}