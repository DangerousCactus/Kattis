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

  string s;
  while (cin >> s) {
    set<char> ch(all(s));
    set<string> candidates;

    int out = 0;
    rep(i, 0, sz(s)) {
      rep(j, 1, sz(s)) {
        candidates.insert(s.substr(i, j));
      }
    }

    for (auto &x: candidates) {
      string s1 = x, s2 = x;
      s1.pop_back();
      s2 = s2.substr(1);

      out += sz(set<char>(all(s1))) != sz(ch) && sz(set<char>(all(s2))) != sz(ch) && sz(set<char>(all(x))) == sz(ch);
    }

    cout << out << '\n';
  }
}