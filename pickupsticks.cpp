#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi topoSort(const vector<vi> &gr) {
  vi indeg(sz(gr)), ret;
  for (auto &li : gr)
    for (int x : li)
      indeg[x]++;
  queue<int> q;
  rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
  while (!q.empty()) {
    int i = q.front();
    ret.push_back(i);
    q.pop();
    for (int x : gr[i])
      if (--indeg[x] == 0)
        q.push(x);
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, a, b;
  cin >> n >> m;

  vector<vi> order(n);

  while (m--) {
    cin >> a >> b;
    order[a - 1].push_back(b - 1);
  }

  vi temp = topoSort(order);

  if (sz(temp) != n) {
    cout << "IMPOSSIBLE";
  } else {
    for (auto &&x : temp)
      cout << (x + 1) << endl;
  }

  return 0;
}