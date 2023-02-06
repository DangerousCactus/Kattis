#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s1, s2;
  cin >> s1 >> s2;

  int total = 1;
  rep(i, 0, 4) if (s1[i] != s2[i]) total *= 2;
  cout << total;

  return 0;
}