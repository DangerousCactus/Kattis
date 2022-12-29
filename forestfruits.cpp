#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> pii;

const ll INF = LLONG_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int v, e, c, k, m;
  cin >> v >> e >> c >> k >> m;

  // home is at 1
  vector<pii> neighbours[v + 1];
  vector<ll> d(v + 1, INF);

  rep(i, 0, e) {
    int a, b, w;
    cin >> a >> b >> w;
    neighbours[a].emplace_back(w, b);
    neighbours[b].emplace_back(w, a);
  }

  bool fruit[v + 1] = {false};
  rep(i, 0, c) {
    int z;
    cin >> z;
    fruit[z] = true;
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  bool vis[v + 1] = {false};
  pq.emplace(0, 1);

  while (pq.size()) {
    auto t = pq.top();
    pq.pop();

    if (vis[t.second])
      continue;

    vis[t.second] = true;

    d[t.second] = min(d[t.second], t.first);

    for (auto &&x : neighbours[t.second])
      if (!vis[x.second])
        pq.emplace(d[t.second] + x.first, x.second);
  }

  vector<ll> fd;

  rep(i, 1, v + 1) {
    if (fruit[i] && (d[i] != INF)) {
      fd.push_back(d[i]);
    }
  }

  sort(all(fd));

  if (k <= fd.size()) {
    cout << fd[min(m, k) - 1] * 2;
  } else if (k > fd.size()) {
    if (m <= fd.size()) {
      cout << fd[m - 1] * 2;
    } else {
      cout << -1;
    }
  }

  return 0;
}