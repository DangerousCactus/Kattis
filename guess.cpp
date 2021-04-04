#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int guess(int g) {
  string s;
  cout << g << endl;
  cin >> s;

  if (s == "lower")
    return -1;
  else if (s == "higher")
    return 1;
  else
    exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int lo = 0;
  int hi = 1000;

  while (lo + 1 < hi) {
    int mid = (lo + hi + 1) / 2;

    int res = guess(mid);

    if (res == 1) {
      lo = mid;
    } else if (res == -1) {
      hi = mid - 1;
    }
  }

  cout << hi;
  return 0;
}