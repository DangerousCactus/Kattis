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

  int n, e, d;
  cin >> n >> e >> d;

  vi drawOrder(n), kittens(e), defuse(d), inventory(n, 0);

  iota(drawOrder.begin(), drawOrder.end(), 0);

  for (auto&& x : kittens)
    cin >> x;

  for (auto&& x : defuse)
    cin >> x;

  sort(kittens.begin(), kittens.end());
  sort(defuse.begin(), defuse.end());

  auto ki = kittens.begin();
  auto di = defuse.begin();

  int currPerson = 0;  // index in drawOrder, next person to draw
  int currCard = 0;    // number of next card to draw

  while (drawOrder.size() > 1 && ki != kittens.end()) {
    if (di != defuse.end() && *di < *ki) {
      currPerson = (currPerson + (*di - currCard)) % drawOrder.size();

      if (inventory[drawOrder[currPerson]] < 5)
        inventory[drawOrder[currPerson]]++;

      currCard = *di++;
      currPerson++;
    } else {
      currPerson = (currPerson + (*ki - currCard)) % drawOrder.size();
      if (inventory[drawOrder[currPerson]]) {
        inventory[drawOrder[currPerson]]--;
        currPerson++;
      } else {
        drawOrder.erase(drawOrder.begin() + currPerson);
      }

      currCard = *ki++;
    }

    currPerson %= drawOrder.size();
    currCard++;
  }

  if (drawOrder.size() == 1) {
    cout << drawOrder.front();
  } else {
    cout << -1;
  }

  return 0;
}