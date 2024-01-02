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

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);
  vector<bool> vis(n), color(n);

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;

    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ncomps = 0;
  bool oddcycle = false;

  rep(i, 0, n) {
    if (vis[i]) {
      continue;
    }

    int ch = 1;
    ncomps++;

    queue<pii> q;
    q.push({i, true});

    while (sz(q)) {
      auto [z, clr] = q.front();
      q.pop();

      vis[z] = true;
      color[z] = clr;

      for (auto &&x : adj[z]) {
        if (vis[x]) {
          if (clr == color[x]) {
            oddcycle = true;
          }
        } else {
          q.emplace(x, !clr);
        }
      }
    }
  }

  cout << ncomps - 1 + !oddcycle;

  return 0;
}