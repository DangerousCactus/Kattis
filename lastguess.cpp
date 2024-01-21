#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <bits/extc++.h>

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;

    MCMF(int N) :
            N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
            seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, ll cap, ll cost) {
      this->cap[from][to] = cap;
      this->cost[from][to] = cost;
      ed[from].push_back(to);
      red[to].push_back(from);
    }

    void path(int s) {
      fill(all(seen), 0);
      fill(all(dist), INF);
      dist[s] = 0;
      ll di;
      __gnu_pbds::priority_queue<pair<ll, int>> q;
      vector<decltype(q)::point_iterator> its(N);
      q.push({0, s});
      auto relax = [&](int i, ll cap, ll cost, int dir) {
          ll val = di - pi[i] + cost;
          if (cap && val < dist[i]) {
            dist[i] = val;
            par[i] = {s, dir};
            if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
            else q.modify(its[i], {-dist[i], i});
          }
      };
      while (!q.empty()) {
        s = q.top().second;
        q.pop();
        seen[s] = 1;
        di = dist[s] + pi[s];
        for (int i: ed[s])
          if (!seen[i])
            relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
        for (int i: red[s])
          if (!seen[i])
            relax(i, flow[i][s], -cost[i][s], 0);
      }
      rep(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<ll, ll> maxflow(int s, int t) {
      ll totflow = 0, totcost = 0;
      while (path(s), seen[t]) {
        ll fl = INF;
        for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
          fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
        totflow += fl;
        for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
          if (r) flow[p][x] += fl;
          else flow[x][p] -= fl;
      }
      rep(i, 0, N) rep(j, 0, N) totcost += cost[i][j] * flow[i][j];
      return {totflow, totcost};
    }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int g, l;
  cin >> g >> l;

  vector<set<char>> posToLetters(l);
  rep(i, 0, l) {
    rep(j, 0, 26) {
      posToLetters[i].insert('a' + j);
    }
  }

  map<char, int> minCt, maxCt;
  rep(i, 0, 26){
    maxCt['a' + i] = 5000;
  }

  rep(i, 0, g - 1) {
    string s1, s2;
    map<char, int> green, yellow, black;
    cin >> s1 >> s2;

    rep(j, 0, l) {
      switch (s2[j]) {
        case 'G':
          posToLetters[j].clear();
          posToLetters[j].insert(s1[j]);
          green[s1[j]]++;
          break;
        case 'Y':
          posToLetters[j].erase(s1[j]);
          yellow[s1[j]]++;
          break;
        case 'B':
          posToLetters[j].erase(s1[j]);
          black[s1[j]]++;
          break;
      }
    }

    rep(j, 0, 26) {
      char key = 'a' + j;
      minCt[key] = max(minCt[key], green[key] + yellow[key]);
      if (black[key] > 0) {
        maxCt[key] = green[key] + yellow[key];
      }
    }
  }

  // 0 = source, 1 = sink, 2, dummy for max,  3-28 = letters, 29+ = positions
  MCMF mcmf(l + 29);
  rep(i, 0, 26) {
    int key = 3 + i;

    mcmf.addEdge(0, key, minCt['a' + i], 0);
    mcmf.addEdge(0, 2, 10000, 0);
    mcmf.addEdge(2, key, maxCt['a' + i] - minCt['a' + i], 1);
  }

  rep(i, 0, l) {
    mcmf.addEdge(29 + i, 1, 1, 0);

    for (auto &c: posToLetters[i]) {
      mcmf.addEdge(c - 'a' + 3, 29 + i, 1, 0);
    }
  }

  auto res = mcmf.maxflow(0, 1);

  string out;

  rep(i, 0, l) {
    rep(j, 0, 26) {
      int key = 3 + j;
      if (mcmf.flow[key][29 + i]) {
        out += 'a' + j;
        break;
      }
    }
  }

  cout << out;
}