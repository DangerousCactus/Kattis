#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x;
  cin >> x;

  int curr = 2;
  ll total = 0;
  while (x > 1 && curr < 31623) {
    if (x % curr == 0) {
      x /= curr;
      ++total;
    } else
      ++curr;
  }

  if (x != 1)
    ++total;

  cout << total;

  return 0;
}