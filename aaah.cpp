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
  string n, h;
  cin >> h >> n;

  cout << ((h.size() >= n.size()) ? "go" : "no");
  return 0;
}