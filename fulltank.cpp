#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi prices;
vector<vector<pii>> adj;
bool vis[1000][100];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q, a, b, c;
  cin >> n >> m;

  prices.resize(n);
  adj.resize(n);

  for (auto &&x : prices)
    cin >> x;

  while (m--) {
    cin >> a >> b >> c;
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, c);
  }

  cin >> q;
  while (q--) {
    cin >> c >> a >> b;

    int best = INT_MAX;
    memset(vis, false, sizeof vis);
    priority_queue<vi, vector<vi>, greater<vi>> pq; // cost, curr, gas
    pq.push({0, a, 0});

    while (sz(pq)) {
      auto z = pq.top();
      pq.pop();

      if (vis[z[1]][z[2]])
        continue;

      vis[z[1]][z[2]] = true;

      if (z[1] == b) {
        best = min(best, z[0]);
        continue;
      }

      for (auto &&x : adj[z[1]])
        if (z[2] >= x.second && !vis[x.first][z[2] - x.second])
          pq.push({z[0], x.first, z[2] - x.second});

      if (z[2] < c && !vis[z[1]][z[2] + 1])
        pq.push({z[0] + prices[z[1]], z[1], z[2] + 1});
    }

    if (best == INT_MAX) {
      cout << "impossible" << endl;
    } else {
      cout << best << endl;
    }
  }
}