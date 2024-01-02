#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// 1680 1118

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pii> diffs = {mp(0, 2018),  mp(1680, 1118),   mp(1118, 1680),
                       mp(0, -2018), mp(1680, -1118),  mp(1118, -1680),
                       mp(2018, 0),  mp(-1680, 1118),  mp(-1118, 1680),
                       mp(-2018, 0), mp(-1680, -1118), mp(-1118, -1680)};

  int n;
  cin >> n;

  pii x;
  set<pii> s;

  rep(i, 0, n) {
    cin >> x.first >> x.second;
    s.insert(x);
  }

  int total = 0;

  for (auto &&x : s) {
    for (auto &&y : diffs) {
      total += s.count(mp(x.first + y.first, x.second + y.second));
    }
  }

  cout << total / 2;

  return 0;
}