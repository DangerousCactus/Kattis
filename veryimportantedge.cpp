#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
    vi e;

    UF(int n) : e(n, -1) {}

    int size(int x) { return -e[find(x)]; }

    int find(int x) { return e[x] < 0 ? x : find(e[x]); }

    bool join(int a, int b) {
      a = find(a), b = find(b);
      if (a == b) return false;
      if (e[a] > e[b]) swap(a, b);
      e[a] += e[b];
      e[b] = a;
      return true;
    }
};


int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  typedef tuple<int, int, int> tiii;

  priority_queue<tiii, vector<tiii>, greater<>> pq;

  rep(i, 0, m) {
    int a, b, w;
    cin >> a >> b >> w;
    pq.emplace(w, a - 1, b - 1);
  }

  UF uf(n);
  ll cost = 0;
  vector<priority_queue<pii, vector<pii>, greater<>>> otherEdges(n);
  vector<vector<pii>> treeEdges(n);
  vi deg(n);

  while (sz(pq)) {
    auto [w, a, b] = pq.top();
    pq.pop();

    if (uf.join(a, b)) {
      cost += w;
      treeEdges[a].emplace_back(w, b);
      treeEdges[b].emplace_back(w, a);
      deg[a]++;
      deg[b]++;
    } else {
      otherEdges[a].emplace(w, b);
      otherEdges[b].emplace(w, a);
    }
  }

  queue<int> q;
  rep(i, 0, n) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }

  uf = UF(n);
  int best = 0;
  while (sz(q)) {
    auto z = q.front();
    q.pop();

    if (--deg[z] < 0) {
      break;
    }

    // a non tree edge must exist
    while (uf.find(z) == uf.find(otherEdges[z].top().second)) {
      otherEdges[z].pop();
    }

    int idx = 0;
    while (deg[treeEdges[z][idx].second] < 1) {
      idx++;
    }

    auto [c, p] = treeEdges[z][idx];

    if (--deg[p] == 1) {
      q.push(p);
    }

    best = max(best, otherEdges[z].top().first - c);
    uf.join(z, p);

    if (sz(otherEdges[z]) > sz(otherEdges[p])) {
      swap(otherEdges[z], otherEdges[p]);
    }

    while (sz(otherEdges[z])) {
      if(uf.find(otherEdges[z].top().second) != uf.find(z)) {
        otherEdges[p].push(otherEdges[z].top());
      }
      otherEdges[z].pop();
    }
  }

  cout << cost + best;
}