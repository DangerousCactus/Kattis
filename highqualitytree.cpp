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

  int n;
  cin >> n;

  vector<vi> adj(n);
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }

  vector<bool> vis(n);
  int ct = 0;

  function<map<int, int>(int, int)> dfs = [&](int curr, int depth) -> map<int, int> {
      vis[curr] = true;

      vector<map<int, int>> v;
      for (auto &x: adj[curr]) {
        if (!vis[x]) {
          v.push_back(dfs(x, depth + 1));
        };
      }

      while(sz(v) < 2){
        v.push_back({{depth, 0}});
      }

      rep(z, 0, 2) {
        while (v[0].rbegin()->first - 1 > v[1].rbegin()->first) {
          ct += v[0].rbegin()->second;
          v[0].erase(v[0].rbegin()->first);
        }

        swap(v[0], v[1]);
      }

      for (auto &[k, va]: v[1]) {
        v[0][k] += va;
      }

      v[0][depth]++;
      return v[0];
  };

  dfs(0, 0);
  cout << ct;
}