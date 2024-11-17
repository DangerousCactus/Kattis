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

  int n, m;
  cin >> n >> m;

  vi denoms(n);
  for(auto & x : denoms){
    cin >> x;
  }

  vector<pair<char, int>> queries(m);
  vi removed;
  for(auto &[a, b] : queries){
    cin >> a >> b;
    if(a == 'X'){
      removed.push_back(b);
    }
  }

  sort(all(denoms));
  sort(all(removed));
  vi result;
  set_difference(all(denoms), all(removed), back_inserter(result));

  reverse(all(queries));

  vi ans;
  vi DP(1E5 + 8, 1E6);
  DP[0] = 0;

  rep(i, 0, 1E5 + 2){
    for(auto & d : result){
      if(i + d < 1E5 + 2){
        DP[i + d] = min(DP[i + d], DP[i] + 1);
      }
    }
  }

  for(auto & [a, b] : queries){
    if(a == 'Q'){
      ans.push_back(DP[b] != 1E6 ? DP[b] : -1);
    }else{
      rep(i, 0, 1E5){
        if(i + b < 1E5 + 2){
          DP[i + b] = min(DP[i + b], DP[i] + 1);
        }
      }
    }
  }

  reverse(all(ans));
  for(auto & x : ans){
    cout << x << '\n';
  }
}