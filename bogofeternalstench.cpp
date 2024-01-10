#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = LLONG_MAX / 2;

struct Ed {
  int a, b, w;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<Ed> edges;

  rep(i, 0, m) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({b - 1, a - 1, w});
  }

  ll lo = -1, hi = inf;  // (]
  while (lo + 1 < hi) {
    ll mid = (lo + hi) / 2;

    vector<ll> dist(n, inf);
    dist[n - 1] = -mid;

    rep(i, 0, n) for (Ed ed : edges) {
      ll d = dist[ed.a] + ed.w;
      if (d <= 0 && d < dist[ed.b]) {
        dist[ed.b] = d;
      }
    }

    vector<bool> posCycle(n);

    for (Ed ed : edges) {
      ll d = dist[ed.a] + ed.w;
      if (d <= 0 && d < dist[ed.b]) {
        posCycle[ed.b] = true;
      }
    }

    rep(i, 0, n) {
      if (posCycle[i]) {
        dist[i] = -inf;
      }
    }

    rep(i, 0, n) for (Ed ed : edges) {
      ll d = dist[ed.a] + ed.w;
      if (d <= 0 && d < dist[ed.b]) {
        dist[ed.b] = d;
      }
    }

    if (dist[0] <= 0) {
      hi = mid;
    } else {
      lo = mid;
    }
  }

  cout << hi;
}