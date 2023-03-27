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

  int n, u, d, z = 0;
  cin >> n;

  vector<vector<int>> out(n);
  multimap<int, int> m;

  while (n--) {
    cin >> u;

    auto it = m.upper_bound(-u);
    d = it->second;

    if (it == m.end())
      d = z++;
    else
      m.erase(it);

    out[d].push_back(u);
    m.insert({-u, d});
  }

  cout << z << '\n';

  for (auto &&x : out) {
    for (auto y : x)
      cout << y << ' ';
    cout << '\n';
  }
}