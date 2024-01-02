#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct AhoCorasick {
    enum {
        alpha = 2, first = '0'
    };

    struct Node {
        int back, next[alpha], start = -1, end = -1, nmatches = 0;

        Node(int v) { memset(next, v, sizeof(next)); }
    };

    vector<Node> N;
    vi backp;

    void insert(string &s, int j) {
      assert(!s.empty());
      int n = 0;
      for (char c: s) {
        int &m = N[n].next[c - first];
        if (m == -1) {
          n = m = sz(N);
          N.emplace_back(-1);
        } else n = m;
      }
      if (N[n].end == -1) N[n].start = j;
      backp.push_back(N[n].end);
      N[n].end = j;
      N[n].nmatches++;
    }

    AhoCorasick(vector<string> &pat) : N(1, -1) {
      rep(i, 0, sz(pat)) insert(pat[i], i);
      N[0].back = sz(N);
      N.emplace_back(0);

      queue<int> q;
      for (q.push(0); !q.empty(); q.pop()) {
        int n = q.front(), prev = N[n].back;
        rep(i, 0, alpha) {
          int &ed = N[n].next[i], y = N[prev].next[i];
          if (ed == -1) ed = y;
          else {
            N[ed].back = y;
            (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
            N[ed].nmatches += N[y].nmatches;
            q.push(ed);
          }
        }
      }
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string p;
  cin >> n >> p;

  vector<string> pats(1, "");
  for (auto c: p) {
    vector<string> newpats;
    for (auto &pat: pats) {
      newpats.push_back(pat + '1');
      if (c == '*') {
        newpats.push_back(pat + '0');
      }
    }
    pats = newpats;
  }

  auto ahc = AhoCorasick(pats);
  vector<vector<ll>> DP(52, vector<ll>(1E6, -1));

  function<ll(int, int)> solve = [&](int len, int node) {
      if (DP[len][node] != -1) {
        return DP[len][node];
      }

      if (len == n) {
        return (ll) (ahc.N[node].start != -1);
      }

      if (ahc.N[node].start != -1) { // base of tree
        return DP[len][node]= 2 * solve(len + 1, node);
      } else { // else sum of children
        return DP[len][node]= solve(len + 1, ahc.N[node].next[0]) + solve(len + 1, ahc.N[node].next[1]);
      }
  };

  cout << solve(0, 0);

  return 0;
}