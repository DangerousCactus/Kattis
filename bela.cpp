#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  map<char, int> dominant = {{'A', 11}, {'K', 4},  {'Q', 3}, {'J', 20},
                             {'T', 10}, {'9', 14}, {'8', 0}, {'7', 0}};
  map<char, int> nondominant = {{'A', 11}, {'K', 4},  {'Q', 3}, {'J', 2},
                               {'T', 10}, {'9', 0}, {'8', 0}, {'7', 0}};

  int hands;
  cin >> hands;

  char dom;
  cin >> dom;
  uint64_t total = 0;
  rep(i, 0, 4 * hands){
    char val, suit;
    cin >> val >> suit;
    if(suit == dom){
      total += dominant[val];
    }else{
      total += nondominant[val];
    }
  }
  cout << total;
  return 0;
}