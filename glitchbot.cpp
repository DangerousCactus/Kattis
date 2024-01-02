#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// const vector<pii> dirs = {mp(0, 1), mp(1, 0), mp(0, -1), mp(-1, 0)};

bool simulate(vi moves, int endx, int endy) {
  pii vel = mp(0, 1);
  pii pos = mp(0, 0);

  for (auto&& x : moves) {
    if (x == -1) {
      swap(vel.first, vel.second);
      vel.first *= -1;
    } else if (x == 0) {
      pos.first += vel.first;
      pos.second += vel.second;
    } else if (x == 1) {
      swap(vel.first, vel.second);
      vel.second *= -1;
    }
  }
  return (pos.first == endx && pos.second == endy);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x, y;
  cin >> x >> y;

  int n;
  cin >> n;

  vi moves(n);

  map<int, string> m;
  m[-1] = "Left";
  m[0] = "Forward";
  m[1] = "Right";

  for (auto&& x : moves) {
    string s;
    cin >> s;

    if (s == "Forward") {
      x = 0;
    } else if (s == "Left") {
      x = -1;
    } else if (s == "Right") {
      x = 1;
    }
  }

  rep(i, 0, n) {
    rep(j, -1, 2) {
      vi movesc = moves;
      movesc[i] = j;
      if (simulate(movesc, x, y)) {
        cout << i + 1 << ' ' << m[j];
        return 0;
      }
    }
  }

  return 0;
}