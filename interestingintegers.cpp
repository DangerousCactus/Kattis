#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int n) {
  vector<ll> fib{1, 1};
  while (fib.back() < INT_MAX) {
    fib.push_back(fib[sz(fib) - 1] + fib[sz(fib) - 2]);
  }

  reverse(all(fib));

  rep(i, 1, 1000000) {
    rep(idx, 0, sz(fib) - 1) {
      if (n > fib[idx] * i && (n - fib[idx] * i) % fib[idx + 1] == 0 &&
          (n - fib[idx] * i) / fib[idx + 1] <= i) {
        cout << (n - fib[idx] * i) / fib[idx + 1] << ' ' << i << endl;
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }

  return 0;
}