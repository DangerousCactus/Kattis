#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m;
long double best[10007];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  long double f;
  vector<vector<pair<int, long double>>> corridors(n);

  cin >> n >> m;
  while (n) {
    corridors.clear();
    corridors.resize(n);

    fill(best, best + 10007, 0);
    best[0] = 1;

    rep(i, 0, m) {
      cin >> a >> b >> f;
      corridors[a].pb(mp(b, f));
      corridors[b].pb(mp(a, f));
    }

    queue<int> curr;
    curr.push(0);

    while (curr.size()) {
      for (auto &&x : corridors[curr.front()]) {
        if (best[curr.front()] * x.second > best[x.first]) {
          curr.push(x.first);
          best[x.first] = best[curr.front()] * x.second;
        }
      }
      curr.pop();
    }

    cout << fixed << setprecision(4) << best[n - 1] << endl;
    cin >> n >> m;
  }

  return 0;
}