#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  char c;
  cin >> n;

  vector<bool> parent(n, false);
  vector<vi> connected(n, vi());
  queue<int> hp;
  set<int> vis;

  rep(i, 0, n - 1) {
    cin >> a >> c >> b;

    if (c == '>') {
      parent[b] = true;
      hp.push(b);
    } else {
      connected[a].push_back(b);
      connected[b].push_back(a);
    }
  }

  while (hp.size()) {
    int t = hp.front();
    hp.pop();

    for (auto &&x : connected[t]) {
      parent[x] = true;
      if (vis.insert(x).second)
        hp.push(x);
    }
  }

  rep(i, 0, n) {
    if (!parent[i]) {
      cout << i << ' ';
    }
  }

  return 0;
}