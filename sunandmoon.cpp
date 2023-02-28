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

  int ds, ys, dm, ym;
  cin >> ds >> ys >> dm >> ym;

  ds *= -1;
  dm *= -1;

  while (ds < 0)
    ds += ys;
  while (dm < 0)
    dm += ym;

  while (true) {
    while (ds < dm) {
      ds += ys;
    }

    while (dm < ds) {
      dm += ym;
    }

    if (ds == dm) {
      cout << ds;
      exit(0);
    }
  }

  return 0;
}