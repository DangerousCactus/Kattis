#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vi deg(n);
  bool adj[n][n];

  memset(adj, false, sizeof adj);

  rep(i, 0, n) {
    cout << "? 1 " << i + 1 << endl;
    cin >> deg[i];

    if (deg[i] == -1) {
      exit(0);
    }
  }

  rep(i, 0, n) {
    rep(j, i + 1, n) {
      int ed;
      cout << "? 2 " << i + 1 << ' ' << j + 1 << endl;
      cin >> ed;
      if (ed == -1) {
        exit(0);
      }
      adj[i][j] = adj[j][i] = (ed != deg[i] + deg[j]);
    }
  }

  cout << '!' << endl;
  rep(i, 0, n) {
    rep(j, 0, n) {
      cout << adj[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}