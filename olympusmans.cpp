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

  vi h(n);
  for (auto &x: h) {
    cin >> x;
  }

  auto mx = max_element(h.rbegin(), h.rend());
  pair<ll, ll> b{0, 1};
  int cx = 1;
  for (auto it = next(mx); it != h.rend(); it++) {
    if (b.first * (*mx - *it) < cx * b.second) {
      b = {cx, *mx - *it};
    }
    cx++;
  }

  ll num = (*mx - (4LL + h[0])) * b.first;
  cout << max(0LL, num / b.second - (cx - 1) + 1);
}