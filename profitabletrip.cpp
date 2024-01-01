#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = LLONG_MAX;

struct Ed {
  int a, b, w;
  int s() { return a < b ? a : -a; }
};
struct Node {
  ll dist = inf;
  int prev = -1;
};
void bellmanFord(vector<Node> &nodes, vector<Ed> &eds, int s) {
  nodes[s].dist = 0;
  sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });
  int lim = sz(nodes) / 2 + 2;
  rep(i, 0, lim) for (Ed ed : eds) {
    Node cur = nodes[ed.a], &dest = nodes[ed.b];
    if (abs(cur.dist) == inf)
      continue;
    ll d = cur.dist + ed.w;
    if (d < dest.dist) {
      dest.prev = ed.a;
      dest.dist = (i < lim - 1 ? d : -inf);
    }
  }
  rep(i, 0, lim) for (Ed e : eds) {
    if (nodes[e.a].dist == -inf)
      nodes[e.b].dist = -inf;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, w;
  cin >> n >> m >> w;
  w *= -1;

  vector<Node> nodes(n);
  vector<Ed> ed(n);
  vector<vector<pii>> adj(n);

  rep(i, 0, m) {
    cin >> ed[i].a >> ed[i].b >> ed[i].w;
    ed[i].a--, ed[i].b--;
    ed[i].w *= -1;

    adj[ed[i].b].emplace_back(ed[i].w, ed[i].a);
  }

  bellmanFord(nodes, ed, 0);

  priority_queue<pii> pq;
  vector<bool> vis(n);

  pq.emplace(0, n - 1);
  int best = INT_MAX / 2;

  while (sz(pq)) {
    auto z = pq.top();
    pq.pop();

    if (z.second == 0) {
      best = min(best, z.first);
    }

    if (nodes[z.second].dist == -inf && z.second != n - 1) {
      best = min(best, w + z.first);
    }

    if (vis[z.second]) {
      continue;
    }

    vis[z.second] = true;

    for (auto &&x : adj[z.second]) {
      if (x.first > 0)
        pq.emplace(max(w, z.first + x.first), x.second);
      else
        pq.emplace(z.first + x.first, x.second);
    }
  }

  cout << min(-w, -best);
}