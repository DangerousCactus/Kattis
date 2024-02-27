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

  int n;
  cin >> n;

  vector<set<int>> base(1);
  rep(i, 0, n) {
    int x;
    cin >> x;
    base.front().insert(x);
  }

  rep(i, 0, 4 - n) {
    vector<set<int>> next;
    for (auto &x: base) {
      rep(j, 1, 7) {
        next.push_back(x);
        next.back().insert(j);
      }
    }
    base = next;
  }

  int a = 0;
  for (auto &x: base) {
    a += (sz(x) == 4);
  }

  cout << a << ' ' << sz(base) - a;
}