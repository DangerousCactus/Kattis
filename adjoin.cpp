#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> e;
int dfs(int x, int p) {
  if (sz(e[x]) == 1) {
    return 1;
  }

  int temp = 0;
  for (auto &&z : e[x]) {
    if (z != p) {
      temp = max(temp, dfs(z, x));
    }
  }

  return 1 + temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int c, l;
  cin >> c >> l;

  e.resize(c);
  vi deg, pq; // dist from centroid to farthest leaf

  rep(i, 0, l) {
    int a, b;
    cin >> a >> b;

    e[a].push_back(b);
    e[b].push_back(a);
  }

  for (auto &&x : e) {
    deg.push_back(sz(x));
  }

  int out = 0;

  queue<int> q;
  rep(i, 0, c) {
    if (deg[i] <= 1) {
      q.push(i);
    }
  }

  while (sz(q)) {
    auto z = q.front();
    q.pop();

    if (!deg[z]) {
      // calc dist from farthest pair of leaves
      vi depths(2, 0);
      for (auto &&x : e[z]) {
        depths.push_back(dfs(x, z));
      }

      sort(all(depths), greater<>());
      out = max(out, depths[0] + depths[1]);
      pq.push_back(depths[0]);
    }

    deg[z] = 0;

    for (auto &&x : e[z]) {
      if (--deg[x] == 1) {
        q.push(x);
      }
    }
  }

  sort(all(pq), greater<>());

  if (sz(pq) > 2) {
    out = max(out, pq[1] + pq[2] + 2);
  }

  if (sz(pq) > 1) {
    out = max(out, pq[0] + pq[1] + 1);
  }

  cout << out;

  return 0;
}
