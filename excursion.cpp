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

  string s;
  cin >> s;
  ll total = 0;

  int curr = 0;
  rep(i, 0, s.size()) {
    if (s[i] == '0')
      total += abs(i - curr++);
  }

  int num0 = 0;
  curr = 0;
  rep(i, 0, s.size()) {
    if (s[i] == '0')
      num0++;
    else if (s[i] == '1')
      total += abs(i - num0 - curr++);
  }

  cout << total;
  return 0;
}