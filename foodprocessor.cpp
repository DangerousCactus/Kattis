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

  int s, t, n;
  cin >> s >> t >> n;

  map<int, int> blades; // s[max] = time;
  pii z;

  rep(i, 0, n) {
    cin >> z.first >> z.second;
    if (blades.count(z.first) == 0) {
      blades[z.first] = z.second;
    } else {
      blades[z.first] = min(blades[z.first], z.second);
    }
  }

  blades[t] = 0;

  int best = INT_MAX;
  auto it = blades.rbegin();

  while (it != blades.rend() && it->first >= s) {
    best = min(best, it->second);
    it++;
  }

  if (best == INT_MAX) {
    cout << -1;
    return 0;
  }

  long double curr = s;
  long double time = 0;

  while (it != blades.rend()) {
    time += (log((long double)it->first) - log(curr)) * best / log(0.5L);
    curr = it->first;
    best = min(best, it->second);
    it++;
  }

  cout << scientific << setprecision(30) << time;
}