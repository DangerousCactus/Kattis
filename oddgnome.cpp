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

  int n;
  cin >> n;

  while (n--) {
    int g;
    cin >> g;

    vi gnomes(g);

    for (auto&& x : gnomes)
      cin >> x;

    rep(i, 0, g) {
      if (gnomes[i] != gnomes[0] + i) {
        cout << i + 1 << endl;
        break;
      }
    }
  }

  return 0;
}