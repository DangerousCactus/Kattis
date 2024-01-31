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
  cin >> n >> ws;
  while (n--) {
    set<char> letters;
    rep(i, 0, 26) {
      letters.insert('a' + i);
    }

    string s;
    getline(cin, s);

    for (auto &c: s) {
      if (isalpha(c)) {
        letters.erase(tolower(c));
      }
    }

    if (sz(letters)) {
      cout << "missing ";
      for (auto &x: letters) {
        cout << x;
      }
    } else {
      cout << "pangram";
    }

    cout << '\n';
  }
}