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

  list<char> password;

  string s;
  cin >> s;

  auto it = password.end();

  for (auto c : s) {
    if (islower(c) || isdigit(c)) {
      password.insert(it, c);
    } else {
      if (c == 'L') {
        it--;
      } else if (c == 'R') {
        it++;
      } else if (c == 'B') {
        auto toRemove = --it;
        it--;
        password.erase(toRemove);
        it++;
      }
    }
  }

  for (auto c : password)
    cout << c;
  return 0;
}