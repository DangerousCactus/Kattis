#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, f, s, t;
  cin >> n >> m >> f >> s >> t;

  vector<vector<pair<int, int>>> roads(2 * n);

  rep(poggers, 0, m) {
    int i, j, c;
    cin >> i >> j >> c;
    roads[i].push_back(mp(c, j));
    roads[j].push_back(mp(c, i));

    roads[i + n].push_back(mp(c, j + n));
    roads[j + n].push_back(mp(c, i + n));
  }

  rep(poggers, 0, f) {
    int u, v;
    cin >> u >> v;
    roads[u].push_back(mp(0, n + v));
  }

  vector<ll> d(2 * n, 1E12);

  d[s] = 0;
  using pii = pair<ll, int>;
  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({0, s});

  while (!q.empty()) {
    ll d_v = q.top().first;
    int v = q.top().second;
    q.pop();
    if (d_v != d[v])
      continue;

    for (auto edge : roads[v]) {
      int len = edge.first;
      int to = edge.second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        q.push({d[to], to});
      }
    }
  }

  cout << min(d[t], d[n + t]);

  return 0;
}