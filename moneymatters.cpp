#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<bool> vis(n, false);
  vi owe(n, 0);
  vector<vi> links(n, vi());

  for (auto&& x : owe)
    cin >> x;

  int a, b;
  rep(i, 0, m) {
    cin >> a >> b;
    links[a].pb(b);
    links[b].pb(a);
  }

  bool poss = true;

  rep(i, 0, n) {
    if (!vis[i]) {
      int curr = 0;
      vis[i] = true;

      queue<int> q;
      q.push(i);

      while (!q.empty()) {
        auto f = q.front();
        q.pop();
        curr += owe[f];

        for (auto&& x : links[f])
          if (!vis[x]) {
            vis[x] = true;
            q.push(x);
          }
      }

      if (curr != 0) {
        poss = false;
        break;
      }
    }
  }

  if (poss)
    cout << "POSSIBLE";
  else
    cout << "IMPOSSIBLE";
  return 0;
}