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
  int x, y;
  cin >> x >> y;

  if (x > 0 && y > 0) {
    cout << 1;
  } else if (x < 0 && y > 0) {
    cout << 2;
  } else if (x < 0 && y < 0) {
    cout << 3;
  } else {
    cout << 4;
  }
  return 0;
}