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

  int n, a, b;
  cin >> n;

  vi boys(n);
  for (auto& x : boys) {
    cin >> x;
  }
  sort(all(boys));
  cin >> a >> b;

  ll cost = -1;
  int best = -1;

  vi cand{a, a + 1, b - 1, b};

  rep(i, 0, sz(boys) - 1) {
    auto c = (boys[i + 1] + boys[i]) / 2;
    cand.insert(cand.end(), {c - 1, c, c + 1});
  }

  for (auto& b : boys) {
    cand.insert(cand.end(), {b - 2, b - 1, b + 1, b + 2});
  }

  for (auto& c : cand) {
    if (c % 2 == 0 || c < a || c > b) {
      continue;
    }

    ll curr = LLONG_MAX;
    for (auto& x : boys) {
      curr = min(curr, llabs(x - c));
    }

    if (curr > cost) {
      cost = curr;
      best = c;
    }
  }

  assert(best != -1);
  cout << best;
}