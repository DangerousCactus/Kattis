#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 2E9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vi lodging(n);
  for (auto& x : lodging) {
    cin >> x;
  }

  vector<vector<pii>> adj1(n), adj2(n);
  rep(i, 0, m) {
    int a, b, c1, c2;
    cin >> a >> b >> c1 >> c2;
    adj1[a - 1].emplace_back(c1, b - 1);
    adj1[b - 1].emplace_back(c1, a - 1);
    adj2[a - 1].emplace_back(c2, b - 1);
    adj2[b - 1].emplace_back(c2, a - 1);
  }

  auto dijkstra = [](int start, vector<vector<pii>> adj) {
    vi dist(sz(adj), INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, start);

    while (sz(pq)) {
      auto [c, z] = pq.top();
      pq.pop();

      if (dist[z] < c) {
        continue;
      }

      dist[z] = c;

      for (auto& [c2, x] : adj[z]) {
        if (dist[x] > c + c2) {
          dist[x] = c + c2;
          pq.emplace(c + c2, x);
        }
      }
    }

    return dist;
  };

  vi cost1 = dijkstra(0, adj1);
  vi cost2 = dijkstra(n - 1, adj2);

  int out = INT_MAX;
  rep(i, 0, n) {
    out = min(out, cost1[i] + cost2[i] + lodging[i]);
  }
  cout << out;
}