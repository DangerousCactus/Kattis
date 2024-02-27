#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 998244353;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int r, c;
  cin >> r >> c;

  ll out = r;
  rep(i, 0, c - 1){
    out *= r - 1;
    out %= mod;
  }

  cout << out;
}