#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string mod(string s) {
  string out = s;

  rep(i, 0, (sz(s) + 1) / 2) { out[i] = s[2 * i]; }

  rep(i, 0, sz(s) / 2) { out[sz(s) - 1 - i] = s[2 * i + 1]; }

  return out;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int x, ct = 0;
  string s;
  cin >> x >> s;

  string temp = s;

  do {
    temp = mod(temp);
    ct++;
  } while (temp != s);

  x %= ct;

  rep(i, 0, x) { s = mod(s); }

  cout << s;
}