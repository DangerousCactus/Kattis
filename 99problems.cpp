#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n < 99)
    cout << 99;
  else {
    rep(i, 1, 51) {
      if ((i + n + 1) % 100 == 0) {
        cout << i + n;
        return 0;
      }
    }

    rep(i, 1, 50) {
      if ((-i + n + 1) % 100 == 0) {
        cout << -i + n;
        return 0;
      }
    }
  }
  return 0;
}