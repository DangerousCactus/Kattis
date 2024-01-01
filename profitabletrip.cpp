#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mmax = 2000 + 7;
const int tmax = 100 * 2 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, w;
  cin >> n >> m >> w;

  vector<vector<pii>> e(n); // cost, dest

  rep(i, 0, m) {
    int u, v, t;
    cin >> u >> v >> t;
    e[u - 1].emplace_back(-t, v - 1);
  }

  vector<vector<bool>> DP(n, vector<bool>(mmax * tmax));
  vi best(n, INT_MAX);

  priority_queue<pii, vector<pii>, greater<>> pq;
  pq.emplace(w, 0);

  while (sz(pq)) {
    auto [zc, zn] = pq.top();
    pq.pop();

    zc = max(zc, 0);
    if (DP[zn][zc]) {
      continue;
    }
    DP[zn][zc] = true;

    if(best[zn] < zc){
      continue;
    }
    best[zn] = zc;

    for (auto &[xc, xn] : e[zn]) {
      pq.emplace(zc + xc, xn);
    }
  }

  int idx = 0;
  while (!DP[n - 1][idx]) {
    idx++;
  }

  cout << w - idx;
}