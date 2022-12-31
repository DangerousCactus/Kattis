#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double q, cash = 100;
  cin >> n >> q;

  vector<double> prices(n);

  for (auto &&x : prices)
    cin >> x;

  vector<double> bestcash(n), beststock(n);
  bestcash[0] = 100;
  beststock[0] = (bestcash[0] - q) / prices[0];

  rep(i, 1, n) {
    bestcash[i] = max(bestcash[i - 1], beststock[i - 1] * prices[i] - q);
    beststock[i] = max(beststock[i - 1], (bestcash[i - 1] - q) / prices[i]);
  }

  cout << setprecision(10) << bestcash.back();

  return 0;
}