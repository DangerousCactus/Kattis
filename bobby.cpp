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

  auto fact = [](int x) {
      int out = 1;
      rep(i, 1, x + 1) {
        out *= i;
      }
      return out;
  };

  auto nck = [fact](int n, int k) {
      return fact(n) / fact(k) / fact(n - k);
  };

  int n;
  cin >> n;

  while (n--) {
    int r, s, x, y, w;
    cin >> r >> s >> x >> y >> w;

    long double winChance = 0;
    rep(i, x, y + 1) {
      winChance += pow((s - r + 1) / (long double) s, i) * pow((r - 1) / (long double) s, y - i) * nck(y, i);
    }

    winChance *= w;

    cout << ((winChance > 1 && (abs(winChance - 1) > 1E-6)) ? "yes" : "no") << '\n';
  }
}