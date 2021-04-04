#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  while (cin >> s) {
    int best = 0;
    bool found = false;
    rep(i, 1, s.size()) {            // sz
      rep(j, 0, s.size() - i + 1) {  // st sb
        found = false;
        rep(k, 0, s.size() - i + 1) {  // st
          if (k == j)
            continue;
          if (s.substr(j, i) == s.substr(k, i))
            found = true;
        }
        if (!found)
          break;
      }
      if (!found)
        break;
      else
        best = i;
    }

    cout << best << '\n';
  }

  return 0;
}