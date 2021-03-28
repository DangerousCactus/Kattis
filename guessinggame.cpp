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

  vi higher;
  vi lower;

  int curr;
  string res;

  cin >> curr;
  while (curr != 0) {
    cin >> res >> res;

    if (res == "high") {
      higher.pb(curr);
    } else if (res == "low") {
      lower.pb(curr);
    } else {
      auto minmax = min_element(all(higher));
      auto maxmin = max_element(all(lower));
      if ((maxmin != lower.end() && *maxmin >= curr) ||
          (minmax != higher.end() && *minmax <= curr)) {
        cout << "Stan is dishonest\n";
      } else {
        cout << "Stan may be honest\n";
      }

      higher.clear();
      lower.clear();
    }

    cin >> curr;
  }

  return 0;
}