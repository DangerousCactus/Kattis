#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, p, w;
  cin >> t;

  while (t--) {
    long double total = 0;
    cin >> n;
    vi wood(n, 0);

    for (auto&& x : wood) {
      cin >> p;
      rep(i, 0, p) {
        cin >> w;
        x += w;
      }
    }

    sort(all(wood), greater<int>());

    while (!wood.empty()) {
      total += wood.back() * wood.size();
      wood.pop_back();
    }
    cout.precision(15);
    cout << total / n << '\n';
  }
  return 0;
}