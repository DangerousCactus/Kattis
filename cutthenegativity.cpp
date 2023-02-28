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

  int n, c;
  cin >> n;

  vector<vi> out;

  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) {
      cin >> c;
      if (c > 0)
        out.push_back(vi{i, j, c});
    }
  }

  cout << sz(out) << endl;
  for (auto &&x : out) {
    cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
  }

  return 0;
}