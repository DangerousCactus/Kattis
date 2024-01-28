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

  int n;
  cin >> n;
  vector<pii> ranks(n); //ar <= r <= br

  for (auto &[a, b] : ranks) {
    cin >> a >> b;
    a--, b--;
  }

  vector<bool> used(n);

  rep(i, 0, n) {
    rep(j, i + 1, n) {
      rep(k, j + 1, n) {
        if (used[i] || used[j] || used[k]) {
          continue;
        }

        if (i >= ranks[j].first && i <= ranks[j].second &&
            i >= ranks[k].first && i <= ranks[k].second &&
            j >= ranks[i].first && j <= ranks[i].second &&
            j >= ranks[k].first && j <= ranks[k].second &&
            k >= ranks[i].first && k <= ranks[i].second &&
            k >= ranks[j].first && k <= ranks[j].second) {
          used[i] = used[j] = used[k] = true;
        }
      }
    }
  }

  cout << accumulate(all(used), 0) / 3;
}