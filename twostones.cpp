#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define rdi(x) \
  int x;       \
  cin >> x;
#define rdrp(x) \
  rdi(x);       \
  for (; x > 0; x--)
#define pb(x)    push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  cout << ((t % 2 == 0) ? "Bob" : "Alice");

  return 0;
}