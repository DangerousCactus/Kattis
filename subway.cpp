#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string solve(string s) {
  if (s == "01") {
    return s;
  }

  vector<string> t;

  int ct = 0;
  int last = 1;

  rep(i, 1, sz(s) - 1) {
    if (s[i] == '0') {
      ct++;
    } else if (s[i] == '1') {
      ct--;
    }

    if (ct == 0) {
      t.push_back(s.substr(last, i - last + 1));
      last = i + 1;
    }
  }

  string out;
  for (auto &&x : t) {
    x = solve(x);
  }

  sort(all(t));

  for (auto &&x : t) {
    out += x;
  }

  return '0' + out + '1';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;

    if (sz(s1) != sz(s2)) {
      cout << "different" << '\n';
      continue;
    }

    s1 = solve('0' + s1 + '1');
    s2 = solve('0' + s2 + '1');

    if (s1 == s2) {
      cout << "same" << '\n';
    } else {
      cout << "different" << '\n';
    }
  }
}