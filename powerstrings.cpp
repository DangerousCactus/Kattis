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
  for (cin >> s; s != "."; cin >> s) {
    int best = 1;

    for (auto i = 1; i <= s.size() / 2; ++i) {
      if (s.size() % i != 0)
        continue;

      best = s.size() / i;
      for (auto j = s.c_str(); j < s.c_str() + s.size() - i; j += i) {
        if (memcmp(j, j + i, i) != 0) {
          best = 1;
          break;
        }
      }

      if (best != 1)
        break;
    }

    cout << best << '\n';
  }

  return 0;
}