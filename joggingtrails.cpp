#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int d[20][20];
int DP[1 << 20];

int solve(int parity) {
  if (parity == 0)
    return 0;

  if (DP[parity] != 0)
    return DP[parity];

  DP[parity] = INT_MAX;

  rep(i, 0, n) {
    rep(j, i + 1, n) {
      if (parity & (1 << i)) {
        if (parity & (1 << j)) {
          DP[parity] =
              min(DP[parity], solve(parity ^ ((1 << i) | (1 << j))) + d[i][j]);
        }
      }
    }
  }

  return DP[parity];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int m, a, b, c;

  while (cin >> n >> m) {
    rep(i, 0, 20) {
      rep(j, 0, 20) { d[i][j] = 1E6; }
    }

    memset(DP, 0, sizeof DP);

    int parity = 0;
    int total = 0;

    while (m--) {
      cin >> a >> b >> c;
      a--;
      b--;

      total += c;
      d[a][b] = d[b][a] = min(d[a][b], c);

      parity ^= (1 << a);
      parity ^= (1 << b);
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }

    cout << total + solve(parity) << endl;
  }

  return 0;
}