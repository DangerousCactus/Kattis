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

  vi slices(n);
  for (auto &x : slices) {
    cin >> x;
    if (x > 2) {
      x = (x % 2) + 2;
    }
  }

  auto mex = [](unordered_set<int> &s) {
    int out = 0;
    while (s.count(out)) {
      out++;
    }
    return out;
  };

  function<bool(vi)> canWin = [&](vi v) {
    bool out = false;

    if (sz(v) == 1) {
      return (v.front() % 2 == 0);
    }

    rep(i, 0, sz(v)) {
      // take one
      vi temp = v;
      if (v[i] > 1) {
        temp[i]--;
        out = out || !canWin(temp);
        temp[i]++;
      }

      temp.erase(temp.begin() + i);
      out = out || !canWin(temp);
    }

    return out;
  };

  if (canWin(slices)) {
    cout << "Ja";
  } else {
    cout << "Nej";
  }
}