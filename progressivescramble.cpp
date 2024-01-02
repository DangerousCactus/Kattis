#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string s;
  unsigned int weAreInting[159];

  while (n--) {
    char c;
    cin >> c;

    getline(cin, s);

    rep(i, 0, s.size()) {
      weAreInting[i] = s[i];

      if (weAreInting[i] == ' ') {
        weAreInting[i] = 0;
      } else {
        weAreInting[i] -= ('a' - 1);
      }
    }

    if (c == 'e') {
      rep(i, 1, s.size()) {
        weAreInting[i] += weAreInting[i - 1];
      }

      rep(i, 1, s.size()) {
        weAreInting[i] %= 27;
        if (weAreInting[i] == 0) {
          weAreInting[i] = ' ';
        } else {
          weAreInting[i] += ('a' - 1);
        }

        cout << (char)weAreInting[i];
      }

      cout << endl;

    } else if (c == 'd') {
      rep(i, 1, s.size()) {
        while (weAreInting[i] < weAreInting[i - 1])
          weAreInting[i] += 27;
      }

      for (int i = s.size() - 1; i > 0; --i) {
        weAreInting[i] -= weAreInting[i - 1];
      }

      rep(i, 1, s.size()) {
        if (weAreInting[i] == 0) {
          weAreInting[i] = ' ';
        } else {
          weAreInting[i] += ('a' - 1);
        }

        cout << (char)weAreInting[i];
      }
      cout << endl;
    }
  }
  return 0;
}
