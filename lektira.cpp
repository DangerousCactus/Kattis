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

  string s, n;
  cin >> s;

  string best;

  rep(i, 1, s.size() - 1) {
    rep(j, 1, s.size() - i) {
      n.assign(s);

      reverse(n.begin(), n.begin() + i);
      reverse(n.begin() + i, n.begin() + i + j);
      reverse(n.begin() + i + j, n.end());

      if (best.empty() || n < best)
        best = n;
    }
  }

  cout << best;
  return 0;
}