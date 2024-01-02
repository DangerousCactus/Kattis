#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x, total = 0, mx = 0;
  cin >> n;

  multimap<int, int, greater<int>> coins;
  rep(i, 0, n) {
    cin >> x;
    coins.emplace(x, i + 1);
    total += x;
    mx = max(mx, x);
  }

  if (total % 2) {
    cout << "no";
    return 0;
  }

  if (mx * 2 > total) {
    cout << "no";
    return 0;
  }

  cout << "yes" << endl;

  rep(j, 0, total / 2) {
    auto a = coins.begin();
    pii y = *a;
    coins.erase(a);
    auto b = coins.begin();
    pii z = *b;
    coins.erase(b);

    cout << y.second << ' ' << z.second << endl;

    if (--y.first) {
      coins.insert(y);
    }
    if (--z.first) {
      coins.insert(z);
    }
  }
}