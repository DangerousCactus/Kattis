#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct Node {
  int pages = 0;
  int total = 0;
  vi lca;
  vi child;
};

vector<Node> tree;

void bfs(int idx) {
  tree[idx].total += tree[idx].pages;

  queue<int> q;
  q.push(idx);
  while (q.size()) {
    auto t = q.front();
    q.pop();
    tree[t].lca.push_back(idx);

    for (auto &&x : tree[t].child)
      q.push(x);
  }

  for (auto &&x : tree[idx].child) {
    tree[x].total = tree[idx].total;
    bfs(x);
  }
}

int lca(int idx1, int idx2) {
  auto a1 = tree[idx1].lca.begin();
  auto a2 = tree[idx2].lca.begin();

  while (*(a1 + 1) == *(a2 + 1)) {
    a1++, a2++;
  }

  return *a1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b;
  cin >> n >> m;

  tree.resize(n + 1);

  rep(t, 1, tree.size()) cin >> tree[t].pages;

  bool hasReq[1111] = {false};

  while (m--) {
    cin >> a >> b;
    tree[a].child.push_back(b);
    hasReq[b] = true;
  }

  rep(i, 1, tree.size()) {
    if (!hasReq[i])
      tree[0].child.push_back(i);
  }

  bfs(0);

  int best = INT_MAX;

  rep(i, 1, tree.size()) {
    if (tree[i].child.size() != 0)
      continue;

    rep(j, i + 1, tree.size()) {
      if (tree[j].child.size() != 0)
        continue;

      best = min(best, tree[i].total + tree[j].total - tree[lca(i, j)].total);
    }
  }

  cout << best;

  return 0;
}