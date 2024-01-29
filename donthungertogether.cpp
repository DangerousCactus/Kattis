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

  int n, k;
  cin >> n >> k;

  vector<pii> food(n);
  for (auto &[q, f]: food) {
    cin >> q >> f;
  }

  typedef pair<int, long double> pid;

  long double lo = 0, hi = 1E18;
  rep(z, 0, 100) {
    long double mid = (lo + hi) / 2;
    bool possible = true;
    priority_queue<pid, vector<pid>, greater<>> pq; // f, q;

    rep(i, 0, n) {
      auto [q, f] = food[i];

      while (sz(pq) && pq.top().first <= i) {
        pq.pop();
      }

      pq.emplace(f, q);

      long double needed = mid;
      while (true) {
        if (!sz(pq)) {
          possible = false;
          break;
        }

        auto [cf, cq] = pq.top();
        pq.pop();

        if (cq < needed) {
          needed -= cq;
        } else {
          pq.emplace(cf, cq - needed);
          break;
        }
      }
    }

    if (possible) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  if (lo == 0) {
    cout << -1;
  } else {
    cout << fixed << setprecision(15) << lo / k;
  }
}