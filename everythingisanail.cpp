#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi obj;
int DP[300007][3][2][2][2];

int solve(int idx, int curr, bool n, bool s, bool b) {
  if (idx < 0)
    return 0;

  if (DP[idx][curr][n][s][b] != INT_MAX) {
    return DP[idx][curr][n][s][b];
  }

  DP[idx][curr][n][s][b] = solve(idx - 1, curr, n, s, b);

  if (obj[idx] == curr) {
    DP[idx][curr][n][s][b] = 1 + solve(idx - 1, curr, n, s, b);
  } else {
    if (obj[idx] == 0 && n) {
      DP[idx][curr][n][s][b] =
          max(DP[idx][curr][n][s][b], 1 + solve(idx - 1, 0, 0, s, b));
    }
    if (obj[idx] == 1 && s) {
      DP[idx][curr][n][s][b] =
          max(DP[idx][curr][n][s][b], 1 + solve(idx - 1, 1, n, 0, b));
    }
    if (obj[idx] == 2 && b) {
      DP[idx][curr][n][s][b] =
          max(DP[idx][curr][n][s][b], 1 + solve(idx - 1, 2, n, s, 0));
    }
  }

  return DP[idx][curr][n][s][b];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  rep(i, 0, 300007) rep(j, 0, 3) rep(k, 0, 2) rep(l, 0, 2) rep(m, 0, 2)
      DP[i][j][k][l][m] = INT_MAX;

  obj.resize(n);
  for (auto &&x : obj)
    cin >> x;

  int a = solve(n - 1, 0, false, true, true);
  int b = solve(n - 1, 1, true, false, true);
  int c = solve(n - 1, 2, true, true, false);

  cout << max(a, max(b, c));
}