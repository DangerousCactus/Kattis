#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

short int children[1000002];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  ll sum = 0;

  rep(i, 1, n) {
    cin >> children[i];
    if (children[i] == 0) {
      i--;
      continue;
    }
    sum += i * children[i];
  }

  ll best = sum;

  rep(i, 1, n){
    sum += children[n - i];
    best = max(best, sum);
  }

  cout << best;

  return 0;
}