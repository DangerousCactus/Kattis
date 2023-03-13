#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool valid(string &s, int idx) {
  while (idx < sz(s)) {
    set<char> c;
    rep(i, 0, 7) {
      if (idx >= sz(s))
        break;

      if (!c.insert(s[idx++]).second)
        return false;
    }
  }

  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    bool p = false;

    rep(i, 0, min(7, sz(s))) {
      set<char> c;
      rep(j, 0, i) { c.insert(s[j]); }

      if (sz(c) == i) {
        p = p || valid(s, i);
      }
    }

    cout << p << endl;
  }
}