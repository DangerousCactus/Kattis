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

  int t, n;
  cin >> t >> n;

  vi p;
  map<int, vi> m;
  m[0] = {};

  rep(i, 0, n) {
    int x;
    cin >> x;
    p.push_back(x);

    for (int j = t - x; j >= 0; j--) {
      if (m.find(j) == m.end() || m.find(j + x) != m.end()) {
        continue;
      }

      m[j + x] = m[j];
      m[j + x].push_back(i);
    }
  }

  map<int, int> out;
  auto best = prev(m.upper_bound(t))->second;

  int time = 0;
  for (auto& x : best) {
    out[x] = time;
    time += p[x];
  }

  time = 0;
  rep(i, 0, n) {
    if (!out.count(i)) {
      out[i] = time;
      time += p[i];
    }
  }

  for (auto& [k, v] : out) {
    cout << v << ' ';
  }
}