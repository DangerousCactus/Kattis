#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> beepers;
pii start, pos;

int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve() {
  int total = 0;

  total += dist(start, beepers.front());

  rep(i, 0, sz(beepers) - 1) total += dist(beepers[i], beepers[i + 1]);

  total += dist(beepers.back(), start);


  return total;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int xs, ys, m;
    beepers.clear();

    cin >> xs >> ys >> start.first >> start.second >> m;

    while (m--) {
      cin >> pos.first >> pos.second;
      beepers.emplace_back(pos.first, pos.second);
    }

    int best = INT_MAX;

    sort(all(beepers));
    do {
      best = min(best, solve());
    } while (next_permutation(all(beepers)));

    cout << best << endl;
  }

  return 0;
}