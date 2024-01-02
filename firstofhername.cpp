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
        alpha = 26, first = 'A'
    }; // change this!
    struct Node {
        // (nmatches is optional)
        int back, next[alpha];
        int ct = 0;

        Node(int v) { memset(next, v, sizeof(next)); }
    };

    vector<Node> N;

    int insert(string &s, int j) {
      assert(!s.empty());
      int n = 0;
      for (char c: s) {
        int &m = N[n].next[c - first];
        if (m == -1) {
          n = m = sz(N);
          N.emplace_back(-1);
        } else n = m;
      }

      return n;
    }

    AhoCorasick() : N(1, -1) {}

    void buildLinks() {
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
            q.push(ed);
          }
        }
      }
    }

    int find(string word) {
      int n = 0;
      for (char c: word) {
        n = N[n].next[c - first];
      }

      return N[n].ct;
    }

};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  AhoCorasick ahc;

  rep(i, 0, n) {
    char c;
    int idx;
    cin >> c >> idx;

    ahc.N[idx].next[c - AhoCorasick::first] = sz(ahc.N);
    ahc.N.emplace_back(-1);
    ahc.N.back().ct = 1;
  }

  string s;
  vi pos;
  rep(i, 0, k) {
    cin >> s;
    reverse(all(s));
    pos.push_back(ahc.insert(s, i));
  }
  ahc.buildLinks();

  vector<vi> adj(sz(ahc.N));
  for (int i = 1; i < sz(ahc.N); i++) {
    adj[ahc.N[i].back].push_back(i);
  }

  function<void(int, int)> dfs = [&](int x, int p) {
      for (auto &u: adj[x]) {
        if (u != p) {
          dfs(u, x);
          ahc.N[x].ct += ahc.N[u].ct;
        }
      }
  };
  dfs(0, -1);

  for (auto &x: pos) {
    cout << ahc.N[x].ct << endl;
  }

  return 0;
}