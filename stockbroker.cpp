#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int d, x;
  cin >> d;

  vi prices;

  vector<bool> peak(d), valley(d);

  prices.pb(INT_MAX);

  rep(i, 0, d) {
    cin >> x;
    prices.pb(x);
  }

  prices.pb(-1);


  rep(i, 0, d){
    peak[i] = prices[i + 1] >= prices[i] && prices[i + 1] >= prices[i + 2];
    valley[i] = prices[i + 1] <= prices[i] && prices[i + 1] <= prices[i + 2];

  }


  ll balance = 100;
  int stock = 0;

  rep(i, 0, d){
    if(valley[i] && balance >= prices[i + 1]){
      if(stock + balance / prices[i + 1] > 100000){
        int diff = 100000 - stock;
        stock = 100000;
        balance -= diff * prices[i + 1];
      }else{
        stock += balance / prices[i + 1];
        balance %= prices[i + 1];
      }
    }

    if(peak[i]){
      balance += stock * prices[i + 1];
      stock = 0;
    }
  }

  cout << balance + stock * prices[d];

  return 0;
}