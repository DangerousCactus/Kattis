#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
  vi e;

  RollbackUF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  while (cin >> n >> m) {
    if (n == 0)
      break;

    int a, b, c;

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    RollbackUF UF(n);
    vector<pii> e;

    while (m--) {
      cin >> a >> b >> c;
      pq.emplace(vi{c, min(a, b), max(a, b)});
    }

    int cost = 0;
    while (sz(pq)) {
      auto z = pq.top();
      pq.pop();

      if (UF.join(z[1], z[2])) {
        cost += z[0];
        e.emplace_back(z[1], z[2]);
      }
    }

    if (UF.size(0) != n) {
      cout << "Impossible" << endl;
    } else {
      cout << cost << endl;

      sort(all(e));
      for (auto &&x : e)
        cout << x.first << ' ' << x.second << endl;
    }
  }

  return 0;
}