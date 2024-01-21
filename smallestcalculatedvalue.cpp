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

  int a, b, c;
  cin >> a >> b >> c;

  vi vals{a + b, a - b, a * b};
  if (a % b == 0) {
    vals.push_back(a / b);
  }

  vi vals2;
  for(auto & x : vals){
    vals2.insert(vals2.end(), {x + c, x - c, x * c});
    if (x % c == 0) {
      vals2.push_back(x / c);
    }
  }

  sort(all(vals2));
  int idx = 0;
  while(vals2[idx] < 0){
    idx++;
  }

  cout << vals2[idx];
}