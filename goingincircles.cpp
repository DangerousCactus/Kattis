#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  string s, enter;

  char curr;
  int idx = 0, nextConsider = 3;

  while (true) {
    s.push_back('0' + rand() % 2);

    cin >> curr;
    enter.push_back(curr);

    if (curr != s[idx++]) {
      cout << "? flip" << endl;
      cin >> curr;
    }

    while (idx > 200 && sz(enter) >= 2 * nextConsider) {
      int fact = sz(enter) / nextConsider;
      if (enter.substr(nextConsider, (fact - 1) * nextConsider) == s.substr(0, (fact - 1) * nextConsider)) {
        cout << "! " << nextConsider << endl;
        return 0;
      }

      nextConsider++;
    }

    cout << "? right" << endl;
  }
}