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

  int s;
  cin >> s;

  long double lo = 1, hi = 1E5;

  rep(i, 0, 100) {
    long double r = (lo + hi) / 2;

    ll ct = 0;
    for(int j = 1; j < r; j++){
      ct += floor(sqrt(r * r - j * j));
    }

    if(4 * ct > s){
      hi = r;
    }else{
      lo = r;
    }
  }

  cout << fixed << setprecision(15) << lo;
}