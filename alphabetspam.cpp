#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  long double sz = s.size();
  int w = 0, l = 0, u = 0, o = 0;

  for (auto c : s) {
    if (isupper(c))
      u++;
    else if (islower(c))
      l++;
    else if (c == '_')
      w++;
    else
      o++;
  }
  cout.precision(10);
  cout << w / sz << '\n' << l / sz << '\n' << u / sz << '\n' << o / sz;

  return 0;
}