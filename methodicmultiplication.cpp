#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s1, s2;
  cin >> s1 >> s2;

  int c = count(all(s1), 'S') * count(all(s2), 'S');
  rep(i, 0, c) cout << "S(";
  cout << "0";
  rep(i, 0, c) cout << ")";
}