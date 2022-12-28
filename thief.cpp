#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int MAXN = 100000;

struct Curve {
  int timeAdded, timeExpired;
  ll offset;
  vector<ll> *partial;

  int lc;

  ll eval(int idx) {
    if (idx >= timeExpired)
      return 0;
    else
      return (*partial)[timeExpired - idx - 1] + offset;
  }

  // c must have an later timeAdded
  int lastRelevant(Curve &c) {
    int lo = timeAdded;   // exclusive
    int hi = timeExpired; // inclusive

    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (this->eval(mid) >= c.eval(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lc = hi;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k, s, v;
  cin >> n >> k;

  vector<vector<ll>> jewels(301);

  rep(i, 0, n) {
    cin >> s >> v;
    jewels[s].push_back(v);
  }

  for (auto &&x : jewels) {
    sort(all(x), greater<>());
    partial_sum(x.begin(), x.end(), x.begin());
  }

  ll sack[100099] = {0};

  rep(js, 1, jewels.size()) { // iterative DP on every size of jewel
    if (jewels[js].size())
      rep(c, 0, js) {            // for each congruence class
        int idx = k - c, wL = 1; // window left index

        deque<Curve> cvs;

        // slide window from right to left on S
        for (int i = 0; idx - i * js > 0; i++) {
          int ipos = idx - i * js;

          // oldest curve is outdated
          while (cvs.size() && cvs.front().timeExpired <= i)
            cvs.pop_front();

          // populate curve window
          while (wL - i <= jewels[js].size() && idx - wL * js >= 0) {
            int wLpos = idx - wL * js;
            Curve cv{i, wL, sack[wLpos], &jewels[js]};

            if (cvs.size())
              cvs.back().lastRelevant(cv);

            // remove all curves that are worse than the one we are about to add
            while (cvs.size() > 1 && cvs[cvs.size() - 2].lc >= cvs.back().lc) {
              cvs.pop_back();
              cvs.back().lastRelevant(cv);
            }

            cvs.push_back(cv);
            wL++;
          }

          // oldest curve is no better than the second oldest curve
          while (cvs.size() > 1 && cvs[0].eval(i) <= cvs[1].eval(i))
            cvs.pop_front();

          // consider the best curve for our DP
          if (cvs.size())
            sack[ipos] = max(sack[ipos], cvs.front().eval(i));
        }
      }
  }

  for_each(sack + 1, sack + k + 1, [](const int &n) { cout << n << ' '; });

  return 0;
}