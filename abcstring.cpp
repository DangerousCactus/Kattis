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

  map<char, int> m{{'A', 1}, {'B', 2}, {'C', 4}};

  string s;
  cin >> s;

  int ans = 0;
  vi ct(8);
  ct[0] = sz(s);

  for (auto &c: s) {
    for (int i = 6; i >= 0; i--) {
      if (ct[i] > 0 && !(m[c] & i)) {
        ct[i]--;
        ct[i | m[c]]++;
        break;
      }
    }

    ans = max(ans, accumulate(ct.begin() + 1, ct.end() - 1, 0));
  }

  cout << ans;
}