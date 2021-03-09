#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int DP[51][27];

int minim(string& s, int start, char needed) {
  if (DP[start][needed - 'a'] != INT_MAX)
    return DP[start][needed - 'a'];

  if (needed == '{') {
    DP[start][needed - 'a'] = 0;
    return 0;
  }

  int find = INT_MAX;
  if (s.find(needed, start) != -1)
    find = minim(s, s.find(needed, start) + 1, needed + 1);
  int synth = minim(s, start, needed + 1) + 1;

  DP[start][needed - 'a'] = min(find, synth);
  return DP[start][needed - 'a'];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  fill(&DP[0][0], &DP[50][26], INT_MAX);

  string s;
  cin >> s;

  cout << minim(s, 0, 'a');

  return 0;
}