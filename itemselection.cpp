#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, s, p, q;
  cin >> n >> m >> s >> p >> q;
  s--;

  set<int> changed;
  int cost = 0;

  vi selected(p), wanted(q);
  for (auto &x: selected) {
    cin >> x;
    x--;
  }

  for (auto &x: wanted) {
    cin >> x;
    x--;
  }

  rep(i, 0, n / m + (n % m != 0)) {
    int first = i * m;
    int last = min(first + m, n); // exclusive
    int rcount = last - first;
    int numSelected = 0, numWanted = 0, numBoth = 0;

    rep(j, first, last) {
      if (find(all(selected), j) != selected.end()) {
        numSelected++;
      }

      if (find(all(wanted), j) != wanted.end()) {
        numWanted++;
      }

      if (find(all(selected), j) != selected.end() && find(all(wanted), j) != wanted.end()) {
        numBoth++;
      }
    }

    int diff = min({1 + numWanted, 1 + (rcount - numWanted), (numSelected - numBoth) + (numWanted - numBoth)});
    cost += diff;

    if(diff){
      changed.insert(i);
    }
  }

  if (sz(changed)) {
    int a = *changed.begin();
    int b = *prev(changed.end());
    cost += min(abs(s - a), abs(s - b)) + abs(a - b);
  }

  cout << cost;
}