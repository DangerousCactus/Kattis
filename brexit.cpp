#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int c, p, x, l;
  cin >> c >> p >> x >> l;
  x--, l--;

  vector<vi> adj(c);
  vi deg(c);
  vector<bool> left(c);

  rep(i, 0, p) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q({l});
  left[l] = true;

  while (sz(q)) {
    auto z = q.front();
    q.pop();

    if (z == x) {
      cout << "leave";
      exit(0);
    }

    for (auto n: adj[z]) {
      deg[n]++;

      if (!left[n]) {
        if (2 * deg[n] >= sz(adj[n])) {
          left[n] = true;
          q.push(n);
        }
      }
    }
  }

  cout << "stay";
}