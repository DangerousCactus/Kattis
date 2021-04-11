#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string token, var, sign;
  map<string, int> m;
  map<int, string> i;
  int val;

  while (cin >> token) {
    if (token == "def") {
      cin >> var >> val;

      if (m.count(var) == 1)
        i.erase(m[var]);

      m[var] = val;
      i[val] = var;
    } else if (token == "calc") {
      bool valid = true;
      int total = 0;
      cin >> token;

      if (m.count(token) == 0)
        valid = false;
      else
        total = m[token];

      cout << token << ' ';
      cin >> sign;
      while (sign != "=") {
        cin >> token;
        cout << sign << ' ' << token << ' ';

        if (m.count(token) == 0) {
          valid = false;
        } else if (valid) {
          total += (2 * (sign == "+") - 1) * m[token];
        }

        cin >> sign;
      }

      cout << "= ";

      if (valid && i.count(total) == 1)
        cout << i[total];
      else
        cout << "unknown";
      cout << '\n';
    } else if (token == "clear") {
      m.clear();
      i.clear();
    }
  }

  return 0;
}