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

  string s1, s2, l;
  int n;
  cin >> s1 >> s2 >> n >> ws;

  while (n--) {
    int a, b;
    char c;
    getline(cin, l);
    stringstream ss(l);

    bool valid = true;

    vector<bool> res;
    while (ss >> a >> c >> b) {
      if (a == b)
        valid = false;

      res.push_back(a > b);

      if (a < b && s1 == "federer")
        valid = false;
      if (a > b && s2 == "federer")
        valid = false;

      if (max(a, b) < 6)
        valid = false;

      if (max(a, b) == 6) {
        if (max(a, b) - min(a, b) < 2)
          valid = false;
      }

      if (sz(res) < 3) {
        if (max(a, b) == 7) {
          if (max(a, b) - min(a, b) > 2)
            valid = false;
        }
        if (max(a, b) > 7)
          valid = false;
      } else {
        if (max(a, b) > 6) {
          if (max(a, b) - min(a, b) != 2)
            valid = false;
        }
      }
    }

    if (sz(res) > 3)
      valid = false;

    if (sz(res) == 3 && res[0] == res[1])
      valid = false;

    if (sz(res) == 2 && res[0] != res[1])
      valid = false;

    if (sz(res) == 1)
      valid = false;

    if (valid)
      cout << "da\n";
    else
      cout << "ne\n";
  }

  return 0;
}