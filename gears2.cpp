#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
struct gear {
  int x, y, r;
  bool vis = false;
  bool dir;
  ll a, b;
};

vector<gear> g;
vector<vi> adj;

bool distg(int a, int b) {
  int r = (g[a].r + g[b].r) * (g[a].r + g[b].r);
  int xd = (g[a].x - g[b].x) * (g[a].x - g[b].x);
  int yd = (g[a].y - g[b].y) * (g[a].y - g[b].y);

  return xd + yd == r;
}

void solve(int t, bool dir, ll a, ll b) {
  g[t].a = a;
  g[t].b = b;

  ll z = __gcd(a, b);
  a /= z;
  b /= z;

  if (g[t].vis) {
    if (g[t].dir == dir) {
      cout << -1;
      exit(0);
    }
    return;
  }

  g[t].vis = true;
  g[t].dir = !dir;

  for (auto &&x : adj[t]) {
    solve(x, !dir, a * g[x].r, b * g[t].r);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;

  g.resize(n);

  for (auto &&x : g)
    cin >> x.x >> x.y >> x.r;

  adj.resize(n);

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (distg(i, j)) {
        adj[i].push_back(j);
      }
    }
  }

  g[0].dir = false;
  solve(0, true, 1, 1);

  if (!g[n - 1].vis) {
    cout << 0;
  } else {
    ll a = g[n - 1].a;
    ll b = g[n - 1].b;

    if (g[n - 1].dir != g[0].dir) {
      b *= -1;
    }

    ll z = __gcd(a, b);
    a /= z;
    b /= z;

    if (a < 0) {
      a *= -1;
      b *= -1;
    }

    cout << a << ' ' << b;
  }

  return 0;
}