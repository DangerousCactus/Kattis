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
  vi fruits(n);

  for (auto &&x : fruits)
    cin >> x;

  ll total = accumulate(all(fruits), 0LL);
  total *= (1LL << (n - 1));

  rep(i, 0, fruits.size()) {
    rep(j, i + 1, fruits.size()) {
      rep(k, j + 1, fruits.size()) {
        if (fruits[i] + fruits[j] + fruits[k] < 200)
          total -= fruits[i] + fruits[j] + fruits[k];
      }
    }
  }

  rep(j, 0, fruits.size()) {
    rep(k, j + 1, fruits.size()) {
      if (fruits[j] + fruits[k] < 200)
        total -= fruits[j] + fruits[k];
    }
  }

  rep(k, 0, fruits.size()) {
    if (fruits[k] < 200)
      total -= fruits[k];
  }

  cout << total;

  return 0;
}