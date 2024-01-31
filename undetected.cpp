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

  auto ds = [](int a, int b) {
      return (a - b) * (a - b);
  };

  int n;
  cin >> n;

  vector<vi> c(n, vi(3));
  rep(i, 0, n) {
    rep(j, 0, 3) {
      cin >> c[i][j];
    }
  }

  rep(i, 0, n) {
    bool possible = true;

    vector<bool> vis(n);
    queue<int> q;

    rep(j, 0, i + 1) {
      if (c[j][0] - c[j][2] < 0) {
        q.push(j);
        vis[j] = true;
      }
    }

    while (sz(q)) {
      auto z = q.front();
      q.pop();

      if (c[z][0] + c[z][2] > 200) {
        possible = false;
      }

      rep(j, 0, i + 1) {
        if (vis[j]) {
          continue;
        }

        if (ds(c[j][0], c[z][0]) + ds(c[j][1], c[z][1]) < ds(c[j][2], -c[z][2])) {
          q.push(j);
          vis[j] = true;
        }
      }
    }


    if (!possible) {
      cout << i;
      exit(0);
    }
  }
}