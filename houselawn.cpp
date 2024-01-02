#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll l, m;
  cin >> l >> m;

  ll best = INT_MAX;
  vector<string> bestnames;

  rep(i, 0, m) {
    string name;
    getline(cin, name, ',');

    ll p, c, t, r;
    char d;
    cin >> p >> d >> c >> d >> t >> d >> r;

    if (t * 10080 * c >= l * (t + r)) {
      if (p < best) {
        best = p;
        bestnames.clear();
      }
      if (p == best) {
        bestnames.push_back(name);
      }
    }
  }

  if (sz(bestnames)) {
    for (auto&& x : bestnames) {
      cout << x << endl;
    }
  } else {
    cout << "no such mower";
  }

  return 0;
}