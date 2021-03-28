#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int temp;

  rep(i, 0, n) {
    cin >> temp;

    cout << temp << " ";

    if (temp % 2) {
      cout << "is odd\n";
    } else {
      cout << "is even\n";
    }
  }
  return 0;
}