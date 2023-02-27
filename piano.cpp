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

  int n;
  cin >> n;

  while (n--) {
    int m, p, a, b;
    cin >> m >> p;
    p /= 2;

    priority_queue<pii, vector<pii>, greater<pii>> pq, bak;

    while (m--) {
      cin >> a >> b;
      pq.emplace(a, b);
    }

    bak = pq;

    bool poss = true;

    for (int day = 1; day <= 100; ++day) {
      if (sz(pq) && pq.top().second < day) {
        poss = false;
        break;
      }

      rep(i, 0, p) {
        if (sz(pq) && pq.top().first <= day) {
          pq.pop();
        } else {
          break;
        }
      }
    }

    if (sz(pq))
      poss = false;

    if (!poss) {
      cout << "serious trouble" << endl;
      continue;
    }

    pq = bak;
    poss = true;
    for (int day = 1; day <= 100; ++day) {
      if (day % 7 == 6 || day % 7 == 0)
        continue;

      if (sz(pq) && pq.top().second < day) {
        poss = false;
        break;
      }

      rep(i, 0, p) {
        if (sz(pq) && pq.top().first <= day) {
          pq.pop();
        } else {
          break;
        }
      }
    }

    if (!poss) {
      cout << "weekend work" << endl;
    } else {
      cout << "fine" << endl;
    }
  }

  return 0;
}