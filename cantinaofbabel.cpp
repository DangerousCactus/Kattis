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
  cin >> n >> ws;

  int idx = 0;
  map<string, int> m;
  string s;

  vi speaks;
  vector<vi> us;

  while (getline(cin, s)) {
    stringstream ss(s);
    us.push_back(vi());
    ss >> s;
    ss >> s;

    if (m.count(s) == 0)
      m[s] = idx++;

    speaks.push_back(m[s]);
    us.back().push_back(m[s]);

    while (ss >> s) {
      if (m.count(s) == 0)
        m[s] = idx++;

      us.back().push_back(m[s]);
    }
  }

  bool adj[n][n] = {false};

  rep(i, 0, n) {   // from
    rep(j, 0, n) { // to
      adj[i][j] = count(us[j].begin(), us[j].end(), speaks[i]);
    }
  }

  rep(k, 0, n) {
    rep(i, 0, n) {
      rep(j, 0, n) { adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]); }
    }
  }

  int mx = 0;

  rep(i, 0, n) {
    int mm = 0;
    rep(j, 0, n) { mm += adj[i][j] && adj[j][i]; }
    mx = max(mx, mm);
  }

  cout << n - mx;

  return 0;
}