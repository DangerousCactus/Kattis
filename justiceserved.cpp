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

  vector<vi> sus(n, vi(3)); //start, duration, index
  rep(i, 0, n) {
    cin >> sus[i][0] >> sus[i][1];
    sus[i][2] = i;
  }

  sort(all(sus), [](vi &a, vi &b) {
      return make_tuple(a[0], -a[1]) < make_tuple(b[0], -b[1]);
  });

  map<int, int> scores; // end, score
  scores[INT_MAX] = -1;

  vi out(n);

  for (auto &x: sus) {
    int endTime = x[0] + x[1];
    out[x[2]] = scores.lower_bound(endTime)->second + 1;

    scores[endTime] = max(scores[endTime], out[x[2]]);
    auto it = scores.find(endTime);

    while (it != scores.begin() && prev(it)->second <= it->second) {
      scores.erase(prev(it));
    }

    if (next(it)->second == out[x[2]]) {
      scores.erase(it);
    }
  }

  for (auto &x: out) {
    cout << x << ' ';
  }
}