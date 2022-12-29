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
  cin >> n;

  string s1, s2;
  while (n--) {
    cin >> s1 >> s2;
    cout << s1 << endl << s2 << endl;

    rep(i, 0, s1.size()) { cout << ((s1[i] == s2[i]) ? '.' : '*'); }

    cout << endl << endl;
  }

  return 0;
}