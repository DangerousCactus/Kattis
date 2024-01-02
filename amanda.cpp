#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int total = 0;
int ct[2];

vi air;
vector<vi> edges;

void v() {
  cout << "impossible";
  exit(0);
}

void dfs(int z, bool c) {
  if (air[z] != -1) {
    if (air[z] != c)
      v();
    return;
  }

  air[z] = c;
  ct[c]++;

  for (auto &&x : edges[z])
    dfs(x, !c);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, a, b, c;
  cin >> n >> m;

  air.resize(n, -1);
  edges.resize(n);

  queue<int> q;

  rep(i, 0, m) {
    cin >> a >> b >> c;
    a--, b--;
    switch (c) {
    case 0:
      if (air[a] == 1 || air[b] == 1)
        v();
      air[a] = air[b] = 0;
      q.push(a), q.push(b);
      break;

    case 1:
      edges[a].push_back(b);
      edges[b].push_back(a);
      break;

    case 2:
      if (air[a] == 0 || air[b] == 0)
        v();
      total += (air[a] == -1) + (air[b] == -1);
      air[a] = air[b] = 1;
      q.push(a), q.push(b);
      break;
    }
  }

  while (q.size()) {
    auto t = q.front();
    q.pop();

    for (auto &&x : edges[t]) {
      if (air[x] == -1) {
        air[x] = 1 - air[t];
        total += air[x];
        q.push(x);
      } else {
        if (air[x] + air[t] != 1)
          v();
      }
    }
  }

  rep(i, 0, n) {
    if (air[i] != -1)
      continue;

    ct[0] = ct[1] = 0;
    dfs(i, true);
    total += min(ct[0], ct[1]);
  }

  cout << total;

  return 0;
}