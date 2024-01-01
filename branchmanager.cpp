#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T> &V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j, 0, sz(jmp[k])) jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b); // or return in f i f a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

struct LCA {
  int T = 0;
  vi time, path, ret;
  RMQ<int> rmq;
  LCA(vector<vi> &C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}
  void dfs(vector<vi> &C, int v, int par) {
    time[v] = T++;
    for (int y : C[v])
      if (y != par) {
        path.push_back(v), ret.push_back(time[v]);
        dfs(C, y, v);
      }
  }
  int lca(int a, int b) {
    if (a == b)
      return a;
    tie(a, b) = minmax(time[a], time[b]);
    return path[rmq.query(a, b)];
  }
  // d is t (a , b){return depth [a ] + depth [ b ] − 2∗depth [ lca (a , b) ] ;}
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);
  vector<bool> removed(n), onPath(n);

  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
  }

  for (auto &x : adj) {
    sort(x.rbegin(), x.rend());
  }

  LCA lca(adj);

  function<void(int)> dfs = [&](int x) {
    removed[x] = true;
    for (auto &z : adj[x]) {
      dfs(z);
    }
  };

  auto update = [&](int x) {
    onPath[x] = true;
    while (sz(adj[x])) {
      x = adj[x].back();
      onPath[x] = true;
    }
    return x;
  };

  int curr = update(0);

  int ct = 0;
  while (m--) {
    int q;
    cin >> q;
    q--;

    if (removed[q]) {
      break;
    }

    while (!onPath[q]) {
      auto l = lca.lca(curr, q);
      dfs(adj[l].back());
      adj[l].pop_back();
      curr = update(l);
    }
    ct++;
  }

  cout << ct;
}