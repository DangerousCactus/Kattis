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

  bool possible = true;
  rep(i, 0, 3){
    vi nums(n);
    for(auto & x : nums){
      cin >> x;
    }
    possible = possible && (find(all(nums), 7) != nums.end());
  }

  if(possible){
    cout << 777;
  }else{
    cout << 0;
  }
}