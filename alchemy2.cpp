#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  int n = sz(s);
  vector<bool> comp;
  map<pair<int, bool>, int> cache;

  rep(i, 0, n / 2) {
    comp.push_back(s[i] == s[n - 1 - i]);
  }

  function<int(int, bool)> solve = [&](int idx, bool force) -> int {
      auto key = make_pair(idx, force);
      if (cache.count(key)) {
        return cache[key];
      }

      if (idx == n / 2) {
        return 0;
      }

      int mn = 1000;

      if (comp[idx]) {
        if(force){
          mn = min(mn, solve(idx + 1, true) + 1);
          mn = min(mn, solve(idx + 1, false) + 1);
        }else{
          mn = min(mn, solve(idx + 1, false));
        }
      } else {
        mn = min(mn, solve(idx + 1, true) + 1);
        if (force) {
          mn = min(mn, solve(idx + 1, false));
          mn = min(mn, solve(idx + 1, true) + 1);
        }
      }

      return cache[key] = mn;
  };

  cout << solve(0, false);
}