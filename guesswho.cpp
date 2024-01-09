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

  int n, m, q;
  cin >> n >> m >> q;

  vector<string> p(n);

  for (auto& x : p) {
    cin >> x;
  }

  set<int> possible;
  rep(i, 0, n) {
    possible.insert(i);
  }

  rep(z, 0, q) {
    int idx;
    char c;
    cin >> idx >> c;

    rep(i, 0, n) {
      if (p[i][idx - 1] != c) {
        possible.erase(i);
      }
    }
  }

  if (sz(possible) > 1) {
    cout << "ambiguous" << '\n' << sz(possible);
  } else {
    cout << "unique" << '\n' << *possible.begin() + 1;
  }
}