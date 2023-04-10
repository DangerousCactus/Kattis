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

  int c;
  cin >> c;

  while (c--) {
    int n, t, m, x;
    string s;

    bool l = false;
    int time = 0;

    cin >> n >> t >> m;

    deque<pii> d[2];
    deque<int> b;
    vi out(m);

    rep(i, 0, m) {
      cin >> x >> s;
      if (s == "left") {
        d[0].emplace_back(x, i);
      } else if (s == "right") {
        d[1].emplace_back(x, i);
      }
    }

    while (sz(d[0]) || sz(d[1])) {
      while (sz(b)) {
        out[b.front()] = time;
        b.pop_front();
      }

      while (sz(d[l]) && d[l].front().first <= time && sz(b) < n) {
        b.push_back(d[l].front().second);
        d[l].pop_front();
      }

      if (sz(b)) {
        l = !l;
        time += t;
      } else {
        int temp = INT_MAX;
        if (sz(d[0])) {
          temp = min(temp, d[0].front().first);
        }
        if (sz(d[1])) {
          temp = min(temp, d[1].front().first);
        }

        if(temp > time) {
          time = temp;
        }

        if (sz(d[l]) && d[l].front().first == time) {
          continue;
        } else {
          l = !l;
          time += t;
        }
      }
    }

    while (sz(b)) {
      out[b.front()] = time;
      b.pop_front();
    }

    for (auto &&x : out) {
      cout << x << '\n';
    }

    cout << '\n';
  }
}