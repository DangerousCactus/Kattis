#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, count = 1;
  cin >> n;

  vector<pii> temps(n); // stored as (high, low)

  for (auto &&x : temps)
    cin >> x.second >> x.first;

  sort(temps.begin(), temps.end()); // sorted in order of highs

  auto it = temps.begin();
  auto currVal = it++->first;

  for (; it != temps.end(); ++it) {
    if (it->second > currVal) {
      currVal = it->first;
      count++;
    }
  }

  cout << count;

  return 0;
}