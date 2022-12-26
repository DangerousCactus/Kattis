#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = INT_MAX;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, q, s, u, v, w, z;
  while (cin >> n >> m >> q >> s) {
    if (n == 0)
      break;

    vector<vector<pii>> neighbours(n);
    vi d(n, INF);

    while (m--) {
      cin >> u >> v >> w;
      neighbours[u].emplace_back(w, v);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, s);

    while (pq.size()) {
      auto t = pq.top();
      pq.pop();

      d[t.second] = min(d[t.second], t.first);

      for (auto &&x : neighbours[t.second])
        if (d[x.second] == INF)
          pq.emplace(d[t.second] + x.first, x.second);
    }

    while (q--) {
      cin >> z;
      if (d[z] == INF)
        cout << "Impossible\n";
      else
        cout << d[z] << '\n';
    }

    cout << '\n';
  }
  return 0;
}