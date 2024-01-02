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

  int n, x;
  cin >> n;

  list<int> cards;

  rep(i, 0, n) {
    cin >> x;
    cards.push_back(x);
  }

  auto it = cards.begin();

  while (it != cards.end()) {
    auto next = it;
    next++;

    if (next != cards.end() && ((*it + *next) % 2 == 0)) {
      cards.erase(next);
      next = it;

      if (next == cards.begin()) {
        cards.erase(next);
        it = cards.begin();
      } else {
        it--;
        cards.erase(next);
      }

    } else {
      it++;
    }
  }

  cout << cards.size();

  return 0;
}