#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1LL << 62;

void floydWarshall(vector<vector<ll>> &m) {
  int n = sz(m);
  rep(i, 0, n) m[i][i] = min(m[i][i], 0LL);
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
        if (m[i][k] != inf && m[k][j] != inf) {
          auto newDist = max(m[i][k] + m[k][j], -inf);
          m[i][j] = min(m[i][j], newDist);
        }
}

pair<int, vi> hungarian(const vector<vi> &a) {
  if (a.empty()) return {0, {}};
  int n = sz(a) + 1, m = sz(a[0]) + 1;
  vi u(n), v(m), p(m), ans(n - 1);
  rep(i, 1, n) {
    p[0] = i;
    int j0 = 0; // add ”dummy” worker 0
    vi dist(m, INT_MAX), pre(m, -1);
    vector<bool> done(m + 1);
    do { // dijkstra
      done[j0] = true;
      int i0 = p[j0], j1, delta = INT_MAX;
      rep(j, 1, m) if (!done[j]) {
          auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
          if (dist[j] < delta) delta = dist[j], j1 = j;
        }
      rep(j, 0, m) {
        if (done[j]) u[p[j]] += delta, v[j] -= delta;
        else dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) { // update alternating path
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  rep(j, 1, m) if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans}; // min cost
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<ll> insp(n);
  for (auto &x: insp) {
    cin >> x;
  }

  vector<vector<ll>> dist(n, vector<ll>(n));
  rep(i, 0, n) {
    rep(j, 0, n) {
      cin >> dist[i][j];
    }
  }

  auto orig = dist;

  rep(i, 0, n) {
    rep(j, 0, n) {
      dist[i][j] += insp[j];
    }
  }
  floydWarshall(dist);

  vector<vi> flights;

  rep(i, 0, m) {
    int s, f, t;
    cin >> s >> f >> t;
    s--, f--;
    flights.push_back({s, f, t});
  }

  vector<vi> a(m, vi(m));
  rep(i, 0, m){
    rep(j, 0, m){
      auto et = flights[i][2] + orig[flights[i][0]][flights[i][1]] + insp[flights[i][1]];
      auto at = et + dist[flights[i][1]][flights[j][0]];
      if(at <= flights[j][2]){
        a[i][j] = 0;
      }else{
        a[i][j] = 1;
      }
    }
  }

  cout << hungarian(a).first;
}