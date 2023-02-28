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

  int s;
  cin >> s;

  vector<pii> wumpus;

  while (sz(wumpus) < 4) {
    s += s / 13 + 15;
    int z = s % 100;
    pii x = {z / 10, z % 10};

    if (find(all(wumpus), x) == wumpus.end())
      wumpus.push_back(x);
  }

  int score = 0;

  while (cin >> s) {
    score++;

    int a = s / 10;
    int b = s % 10;

    auto i = wumpus.begin();
    int d = INT_MAX;

    while (i != wumpus.end()) {
      if (abs(a - i->first) + abs(b - i->second) == 0) {
        cout << "You hit a wumpus!" << endl;
        auto temp = i--;
        wumpus.erase(temp);
      } else {
        d = min(d, abs(a - i->first) + abs(b - i->second));
      }
      i++;
    }

    if (sz(wumpus)) {
      cout << d << endl;
    }
  }

  cout << "Your score is " << score << " moves." << endl;

  return 0;
}