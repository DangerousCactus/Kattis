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

  int k, match = 0;
  string s1, s2;

  cin >> k >> s1 >> s2;
  rep(i, 0, s1.size()) {
    match += s1[i] == s2[i];
  }

  cout << s1.size() - abs((match - k));

  return 0;
}