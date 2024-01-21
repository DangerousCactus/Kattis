#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<set<int>> adj(k);
  vector<bool> vis(k);

  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;

    adj[a - 1].insert(b - 1);
    adj[b - 1].insert(a - 1);
  }

  // for each node, it has at most 2 non-leaf neighbours
  rep(i, 0, k) {
    if (sz(adj[i]) == 0) {
      vis[i] = true;
      continue;
    }

    int nl = 0;
    for (auto x: adj[i]) {
      nl += (x != i && sz(adj[x]) > 1);
    }
    if (nl > 2) {
      cout << "impossible";
      exit(0);
    }
  }

  int cycles = 0, paths = 0;

  rep(i, 0, k) {
    if (vis[i]) {
      continue;
    }

    queue<pii> q;
    q.emplace(i, i);
    vis[i] = true;

    bool cycle = false;

    while (sz(q)) {
      auto [z, p] = q.front();
      q.pop();

      for (auto &x: adj[z]) {
        if (vis[x]) {
          if (x != p && x != z) {
            cycle = true;
          }
        } else {
          q.emplace(x, z);
          vis[x] = true;
        }
      }
    }

    cycles += cycle;
    paths += !cycle;
  }


  if (cycles == 0 || cycles == 1 && paths == 0) {
    cout << "possible";
  } else {
    cout << "impossible";
  }
}