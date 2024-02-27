#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
      for (int i = time(); i --> t;)
        e[st[i].first] = st[i].second;
      st.resize(t);
    }
    bool join(int a, int b) {
      a = find(a), b = find(b);
      if (a == b) return false;
      if (e[a] > e[b]) swap(a, b);
      st.push_back({a, e[a]});
      st.push_back({b, e[b]});
      e[a] += e[b]; e[b] = a;
      return true;
    }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    RollbackUF uf(n);
    priority_queue<vi, vector<vi>, greater<>> pq;
    ll out = 0;
    rep(i, 0, n - 1){
      int a, b, w;
      cin >> a >> b >> w;
      pq.push({w, a - 1, b - 1});
    }

    while(sz(pq)){
      auto z = pq.top();
      pq.pop();
      out += (uf.size(z[1]) * uf.size(z[2]) - 1) * ((ll)z[0] + 1);
      out += z[0];
      uf.join(z[1], z[2]);
    }

    cout << out << '\n';
  }
}