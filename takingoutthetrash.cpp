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

  vi weights(n);
  for(auto & x : weights){
    cin >> x;
  }

  sort(all(weights));
  deque<int> w(all(weights));

  int trips = 0;
  while(sz(w)){
    if(sz(w) == 1){
      trips++;
      break;
    }

    if(w.back() + w.front() <= m){
      w.pop_back();
      w.pop_front();
    }else{
      w.pop_back();
    }

    trips++;
  }

  cout << trips;
}