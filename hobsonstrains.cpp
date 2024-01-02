#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vi to(n), deg(n, 0), age(n, 0), ans(n, 0);
  vector<priority_queue<int, vi, greater<>>> child(n);

  for (auto &x: to) {
    cin >> x;
    deg[--x]++;
  }

  // don't actually need to detect the cycle. EDIT: cycles***

  queue<int> bfs;
  rep(i, 0, n) {
    if (!deg[i]) {
      bfs.push(i);
    }
    child[i].push(k); // age of last validity
  }

  while (sz(bfs)) {
    auto z = bfs.front();
    bfs.pop();

    while (sz(child[z]) && child[z].top() < age[z]) {
      child[z].pop();
    }

    ans[z] = sz(child[z]);
    age[z]++;
    auto next = to[z];

    if (sz(child[z]) > sz(child[next])) {
      swap(child[z], child[next]);
      swap(age[z], age[next]);
    }

    while (sz(child[z])) {
      child[next].push(age[next] + child[z].top() - age[z]);
      child[z].pop();
    }

    if (--deg[next] == 0) {
      bfs.push(next);
    }
  }

  // only cycles remain
  // for each node in a cycle (deg > 2), distribute accordingly
  vector<bool> vis(n, false);

  rep(i, 0, n) {
    if (deg[i]) {
      bfs.push(i);
    }
  }

  while (sz(bfs)) {
    auto z = bfs.front();
    bfs.pop();

    if (vis[z]) {
      continue;
    }

    // find size of cycle
    auto curr = z;
    int clen = 0;

    do {
      vis[curr] = true;
      clen++;
      curr = to[curr];
    } while (curr != z);

    priority_queue<int, vi, greater<>> pq;
    int a = 0;

    do {
      while (sz(child[curr])) {
        pq.push(a + min(child[curr].top() - age[curr], clen - 1));
        child[curr].pop();
      }

      while (sz(pq) && pq.top() < a) {
        pq.pop();
      }

      ans[curr] += sz(pq);
      a++;
      curr = to[curr];
    } while (sz(pq));
  }

  for (auto &x: ans) {
    cout << x << '\n';
  }

  return 0;
}