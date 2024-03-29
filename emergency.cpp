#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k;
  cin >> n >> k;

  if (n <= k)
    cout << n - 1;
  else
    cout << min(n - 1, k + 1 + (n - 1) % k);

  return 0;
}