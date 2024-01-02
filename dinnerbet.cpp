#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ld DP[11][11][11];
vector<vector<ll>> nck;
int n, d;

ld solve(int a, int b, int c) {
  if (a * b == 0 && c == 0) {
    return 0;
  }

  if (DP[a][b][c] != -1) {
    return DP[a][b][c];
  }

  DP[a][b][c] = 1;

  rep(i, 0, a + 1) {
    rep(j, 0, b + 1) {
      rep(k, 0, c + 1) {
        if (i + j + k <= d && n - (a + b + c) >= d - (i + j + k) &&
            i + j + k > 0) {  // not too many balls taken, possbible to take
          DP[a][b][c] +=
              ((ld)nck[a][i] * (ld)nck[b][j] * (ld)nck[c][k] *
               (ld)nck[n - a - b - c][d - i - j - k] / (ld)nck[n][d]) *
              (solve(a - i, b - j, c - k));
        }
      }
    }
  }

  // stay at current position
  if (n - (a + b + c) >= d) {
    DP[a][b][c] /= (1 - (ld)nck[n - (a + b + c)][d] / nck[n][d]);
  }
  return DP[a][b][c];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  rep(i, 0, 11) rep(j, 0, 11) rep(k, 0, 11) DP[i][j][k] = -1;

  // pascal's triangle
  nck.push_back({1});
  nck.push_back({1, 1});
  rep(i, 0, 51) {
    vector<ll> nb{1};
    rep(i, 0, sz(nck.back()) - 1) {
      nb.push_back(nck.back()[i] + nck.back()[i + 1]);
    }
    nb.push_back({1});
    nck.push_back(nb);
  }

  int c;
  cin >> n >> d >> c;

  int a, x = c;
  vector<bool> s(55, false);

  rep(i, 0, c) {
    cin >> a;
    s[a] = true;
  }

  rep(i, 0, c) {
    cin >> a;
    x -= s[a];
  }

  cout << setprecision(15) << solve(x, x, c - x);

  return 0;
}