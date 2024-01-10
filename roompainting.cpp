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
  cin >> n >> m;

  vi sizes(n);
  for (auto& x : sizes) {
    cin >> x;
  }

  sort(all(sizes));

  ll total = 0;
  while (m--) {
    int q;
    cin >> q;

    total += *lower_bound(all(sizes), q) - q;
  }

  cout << total;
}