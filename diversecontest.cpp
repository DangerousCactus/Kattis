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

  map<string, int> m;

  auto id = [&m](string &s) {
      if (m.count(s)) {
        return m[s];
      }
      return m[s] = sz(m);
  };

  int n, k;
  cin >> n >> k;

  vector<set<int>> problems(n);
  for (auto &x: problems) {
    int t;
    cin >> t;

    rep(i, 0, t) {
      string s;
      cin >> s;

      x.insert(id(s));
    }
  }

  int out = 0;
  rep(i, 0, (1 << n)) {
    if (__builtin_popcount(i) != k) {
      continue;
    }

    map<int, int> ct;
    rep(j, 0, n) {
      if (i & (1 << j)) {
        for (auto &x: problems[j]) {
          ct[x]++;
        }
      }
    }

    bool valid = true;
    for (auto &[_, v]: ct) {
      if (v > k / 2) {
        valid = false;
      }
    }

    out += valid;
  }

  cout << out;

}