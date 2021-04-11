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

  int t;
  cin >> t;
  while (t--) {
    int d1, d2;

    cin >> d1;
    vi p1(d1 + 1, 0);
    rep(i, 0, d1 + 1) cin >> p1[i];

    cin >> d2;
    vi p2(d2 + 1, 0);
    rep(i, 0, d2 + 1) cin >> p2[i];

    vi out(d1 + d2 + 1, 0);

    int idx = 0;
    for (auto&& x : p2) {
      rep(i, 0, p1.size()) { out[idx + i] += x * p1[i]; }
      ++idx;
    }

    while (!out.empty() && out.back() == 0)
      out.pop_back();

    cout << out.size() - 1 << '\n';

    for (auto&& x : out)
      cout << x << ' ';

    cout << '\n';
  }

  return 0;
}