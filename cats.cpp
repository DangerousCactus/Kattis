#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int catdist[2007][2007];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int m, c, a, b, d, cost, curr = 0;

    cin >> m >> c;
    cost = c;

    rep(i, 0, (c * c - c) / 2) {
      cin >> a >> b >> d;
      catdist[a][b] = d;
      catdist[b][a] = d;
    }

    int best[c];
    memcpy(best, catdist, c * sizeof(int));
    best[0] = -1;

    rep(i, 1, c) {
      int lowest = 1E6;

      rep(j, 0, c) {
        if (best[j] < lowest && best[j] > 0) {
          lowest = best[j];
          curr = j;
        }
      }

      best[curr] = -1;
      cost += lowest;

      rep(j, 0, c) { best[j] = min(best[j], catdist[curr][j]); }
    }

    if (cost <= m) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}