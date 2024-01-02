#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x, p, sum = 0;
  cin >> n >> p;

  rep(i, 0, n) {
    cin >> x;
    sum += x;
  }

  if (p == 100) {
    cout << "impossible";
  } else {
    int add = 1;
    while (sum + 100 * add < p * (n + add)) {
      add++;
    }
    cout << add;
  }

  return 0;
}