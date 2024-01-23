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

  int n, s, k;
  cin >> n >> s >> k;
  s *= 2;
  k *= 2;

  vi p(n);
  for (auto &x: p) {
    cin >> x;
    x *= 2;
  }

  sort(all(p));
  rep(i, 0, n - 1) {
    if (p[i + 1] - p[i] < s) {
      cout << -1;
      exit(0);
    }
  }

  int lengths = 0;

  int prevEnd = -k;
  rep(i, 0, n - 1) {
    int newLen = min({k, (p[i] - prevEnd) * 2, s + (p[i + 1] - p[i] - s) * 2});
    lengths += newLen;
    prevEnd = p[i] + newLen / 2;
  }

  lengths += min({k, (p[n - 1] - prevEnd) * 2});


  cout << lengths / 2;


}