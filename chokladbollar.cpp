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

  int n, b, s;
  cin >> n >> b >> s;

  if(s > b){
    swap(b, s);
  }

  int target = (b + s) / n;
  int extra = (b + s) - target * n;
  int ans = max(0, b - target - (extra >= 1)) + max(0, s - target - (extra >= 2));

  cout << ans;
}