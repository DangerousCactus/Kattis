#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

unordered_map<string, int> cache;
bool first = true;

int solve(string s) {
  if (cache.count(s)) {
    return cache[s];
  }

  if (sz(s) <= 1) {
    return 0;
  }

  int mn = 10000;

  if (!first) {
    int mn = solve(s.substr(1, sz(s) - 2)) + 1;
  }

  first = false;

  if (s.front() == s.back() || isupper(s.front()) && isupper(s.back())) {
    mn = solve(s.substr(1, sz(s) - 2));
  }

  if (isupper(s.front()) && s.front() != toupper(s.back())) {
    mn = solve(s.substr(1, sz(s) - 2));
  }

  if (isupper(s.back()) && s.back() != toupper(s.front())) {
    mn = solve(s.substr(1, sz(s) - 2));
  }

  string s1 = s.substr(1, sz(s) - 2);
  string s2 = s1;

  if (sz(s1)) {
    s1.front() = toupper(s1.front());
    s2.back() = toupper(s2.back());
  }

  mn = min(mn, solve(s1) + 1);
  mn = min(mn, solve(s2) + 1);

  if (sz(s) >= 4) {
    mn = min(mn, solve(s.substr(2, sz(s) - 4)) + 2);
  }

  return cache[s] = mn;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << solve(s);
}