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

  int n, a, b;
  cin >> n >> a >> b;

  vi cups(n - 1);
  for(auto & x : cups){
    cin >> x;
  }

  if(count(all(cups), a) + count(all(cups), b) == 0){
    cout << -1;
    return 0;
  }

  if(!count(all(cups), a)){
    cout << a;
    return 0;
  }

  if(!count(all(cups), b)){
    cout << b;
    return 0;
  }

  rep(i, a, b + 1){
    cout << i << endl;
  }
}