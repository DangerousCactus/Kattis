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

  int n, m;
  vi out(1E6 + 7);

  while (cin >> n >> m, n != 0) {
    vi jack(n), jill(m);

    for (auto& x : jack) {
      cin >> x;
    }

    for (auto& x : jill) {
      cin >> x;
    }

    auto e = set_intersection(all(jack), all(jill), out.begin());
    cout << distance(out.begin(), e) << '\n';
  }
}