#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 9302023;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<vi> DP(sz(s) + 1, {INT_MAX, -1}); // shortest, how many
  DP[0] = {0, 1};
  const vector<string> nums = {" ", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  rep(i, 0, sz(s)) {
    for (auto &num: nums) {
      if (i + sz(num) <= sz(s)) {
        if (sz(num) > 1 && num != s.substr(i, sz(num))) {
          continue;
        }

        if (DP[i + sz(num)][0] > DP[i][0] + 1) {
          DP[i + sz(num)] = DP[i];
          DP[i + sz(num)][0]++;
        } else if (DP[i + sz(num)][0] == DP[i][0] + 1) {
          DP[i + sz(num)][1] += DP[i][1];
          DP[i + sz(num)][1] %= mod;
        }
      }
    }
  }

  cout << DP[sz(s)][0] << '\n' << DP[sz(s)][1];
}