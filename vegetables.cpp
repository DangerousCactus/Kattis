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

  long double t;
  int n, x, currMin = INT_MAX;

  cin >> t >> n;

  priority_queue<int> weights;

  rep(i, 0, n) {
    cin >> x;
    currMin = min(currMin, x);
    weights.push(x);
  }

  while ((long double)currMin / weights.top()) {
    x = weights.top();
    weights.pop();

    currMin = min(currMin, x - weights.top());
    
    weights.push(weights.top());
    weights.push(x - weights.top());

  }

  return 0;
}