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

  int h, k, v, s, total = 0;
  cin >> h >> k >> v >> s;

  while (h > 0) {
    v += s;
    v -= max(1, v / 10);

    if (v >= k)
      h++;

    if (v > 0 && v < k) {
      h--;
      if (h == 0)
        v = 0;
    }

    if (v <= 0) {
      v = h = 0;
    }

    total += v;
    if (s > 0)
      s--;
  }

  cout << total;

  return 0;
}