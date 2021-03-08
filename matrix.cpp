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

  int ca = 1;
  int a, b, c, d;
  while (cin >> a >> b >> c >> d) {
    int det = a * d - b * c;
    cout << "Case " << ca++ << ":\n";
    cout << d / det << ' ' << (-1) * b / det << '\n';
    cout << (-1) * c / det << ' ' << a / det << '\n';
    cout << '\n';
  }
  return 0;
}