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
  int n, from, to;

  cin >> n;

  vector<vi> indices;
  vector<string> strs;

  indices.resize(n + 1);
  strs.resize(n + 1);

  rep(i, 1, n + 1) { cin >> strs[i]; }

  rep(i, 0, n - 1) {
    cin >> to >> from;
    indices[to].pb(from);
  }

  stack<int> s;
  s.push(to);

  while (!s.empty()) {
    to = s.top();
    s.pop();
    cout << strs[to];
    for (auto i = indices[to].rbegin(); i != indices[to].rend(); i++)
      s.push(*i);
  }

  return 0;
}