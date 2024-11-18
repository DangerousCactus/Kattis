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

  int n;
  cin >> n;

  vector<vector<ll>> events(n, vector<ll>(3));
  for (auto &x : events) {
    string s;
    cin >> s;

    for (auto &y : x) {
      cin >> y;
    }

    if (s == "MISS") {
      x[1] *= -1;
      x[2] *= -1;
    }
  }

  ll cheese = 0;
  ll glory = 0;

  ll k;
  cin >> k;

  for (auto &e : events) {
    if (e[0] < k) {
      cheese += e[1];
      glory += e[2];
    }
  }

  cout << cheese << ' ' << glory;
}