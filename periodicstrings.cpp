#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

string s;
bool isp(int i) {
  if (s.size() % i)
    return false;

  string first = s.substr(0, i);
  for (int idx = i; idx < s.size(); idx += i) {
    string curr = s.substr(idx, i);

    rotate(first.begin(), first.end() - 1, first.end());
    if (first != curr)
      return false;

    first = curr;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  rep(i, 1, s.size() + 1) {
    if (isp(i)) {
      cout << i;
      break;
    }
  }

  return 0;
}