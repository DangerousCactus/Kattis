#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vi rank(n);
  iota(rank.begin(), rank.end(), 1);

  char c;
  int a, b;
  while (m--) {
    cin >> c >> a >> c >> b;
    auto ai = find(rank.begin(), rank.end(), a);
    auto bi = find(rank.begin(), rank.end(), b);

    if(ai > bi){
      move(bi + 1, ai + 1, bi);
      *ai = b;
    }
  }

  for_each(rank.begin(), rank.end(),
           [](const int n) { cout << 'T' << n << ' '; });

  return 0;
}