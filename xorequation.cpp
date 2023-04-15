#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void g(vector<ll> &v, string &s, int idx, ll curr) {
  if (idx == sz(s)) {
    v.push_back(curr);
    return;
  }

  if (s[idx] == '?') {
    if (idx != 0 || sz(s) == 1)
      g(v, s, idx + 1, curr * 10);

    rep(i, 1, 10) { g(v, s, idx + 1, curr * 10 + i); }
  } else {
    g(v, s, idx + 1, curr * 10 + (s[idx] - '0'));
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> v(3);
  cin >> v[0] >> v[1] >> v[1] >> v[2] >> v[2];

  sort(all(v), [](string a, string b) {
    return count(all(a), '?') < count(all(b), '?');
  });

  vector<ll> n1, n2;

  g(n1, v[0], 0, 0);
  g(n2, v[1], 0, 0);

  int ans = 0;

  for (auto &&x : n1) {
    for (auto &&y : n2) {
      string temp = to_string(x ^ y);
      bool poss = true;

      // cout << x << '^' << y << ' ' << to_string(x ^ y) << endl;

      if (sz(temp) != sz(v[2])) {
        continue;
      }

      if (temp == "0" && v[2][0] == '?' || v[2][0] == '0') {
        ans++;
        continue;
      }

      rep(i, 0, sz(temp)) {
        if (temp[i] != v[2][i] && v[2][i] != '?') {
          poss = false;
          break;
        }
      }

      ans += poss;
    }
  }

  cout << ans;
}