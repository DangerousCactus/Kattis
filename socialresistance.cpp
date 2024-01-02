#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<double> vd;
const double eps = 1e-12;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
  int n = sz(A), m = sz(x), rank = 0, br, bc;
  if (n)
    assert(sz(A[0]) == m);
  vi col(m);
  iota(all(col), 0);
  rep(i, 0, n) {
    double v, bv = 0;
    rep(r, i, n) rep(c, i, m) if ((v = fabs(A[r][c])) > bv) br = r, bc = c,
                                                            bv = v;
    if (bv <= eps) {
      rep(j, i, n) if (fabs(b[j]) > eps) return -1;
      break;
    }
    swap(A[i], A[br]);
    swap(b[i], b[br]);
    swap(col[i], col[bc]);
    rep(j, 0, n) swap(A[j][i], A[j][bc]);
    bv = 1 / A[i][i];
    rep(j, i + 1, n) {
      double fac = A[j][i] * bv;
      b[j] -= fac * b[i];
      rep(k, i + 1, m) A[j][k] -= fac * A[i][k];
    }
    rank++;
  }
  x.assign(m, 0);
  for (int i = rank; i--;) {
    b[i] /= A[i][i];
    x[col[i]] = b[i];
    rep(j, 0, i) b[j] -= A[j][i] * b[i];
  }
  return rank;  // (multiple so lutions i f rank < m)
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q, e;
  cin >> n >> q >> e;

  vector<pii> edges;
  while (sz(edges) < e) {
    int l, c, x;
    cin >> l >> c;

    rep(i, 0, c) {
      cin >> x;
      edges.emplace_back(l - 1, x - 1);
    }
  }

  // v_n, i_e
  // n current equations
  // e voltage equations
  vector<vd> m(n + e, vd(n + e, 0));

  rep(i, 0, e) {  // from l to r
    auto x = edges[i];
    m[x.first][n + i] = -1;
    m[x.second][n + i] = 1;

    m[n + i][x.first] = 1;
    m[n + i][x.second] = -1;
    m[n + i][n + i] = -1;
  }

  while (q--) {
    int l, r;
    cin >> l >> l >> r;
    l--;
    r--;

    vd b(n + e + 1, 0);
    b[l] = -1;
    b[r] = 1;

    auto temp = m;
    temp.push_back(vd(n + e, 0));
    temp.back()[l] = 1;

    vd ans(n + e);
    solveLinear(temp, b, ans);
    cout << setprecision(15) << abs(ans[r]) << endl;
  }

  return 0;
}