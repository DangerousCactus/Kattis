#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll MOD = 1E9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int r, c;
    cin >> r >> c;

    ll answer = 18;

    rep(i, 0, r - 1) {
      answer *= 6;
      answer %= MOD;
    }

    rep(i, 0, c - 1) {
      answer *= 6;
      answer %= MOD;
    }

    rep(i, 0, (r - 1) * (c - 1)) {
      answer *= 2;
      answer %= MOD;
    }

    cout << answer << endl;
  }

  return 0;
}