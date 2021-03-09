#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int addends;
  cin >> addends;

  uint64_t total = 0;

  rep(i, 0, addends){
    int in;
    cin >> in;
    total += pow(in / 10, in % 10);
  }

  cout << total;
  return 0;
}