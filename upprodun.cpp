#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  rep(i, 0, n - m%n) cout << string(m/n, '*') << '\n';
  rep(i, 0, m%n) cout << string(m/n + 1, '*') << '\n';

  return 0;
}