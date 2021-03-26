#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;

  vi x;
  vi y;

  rep(i, 0, 3) {
    cin >> a >> b;
    x.pb(a);
    y.pb(b);
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  if (x[1] == x[0]) {
    cout << x[2];
  } else {
    cout << x[0];
  }
  cout << ' ';

  if (y[1] == y[0]) {
    cout << y[2];
  } else {
    cout << y[0];
  }
  return 0;
}