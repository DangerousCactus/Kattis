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

  int n, k;
  cin >> n >> k;

  int last, mx = 1;
  cin >> last;
  deque<int> d{last};

  rep(i, 0, n - 1) {
    int x;
    cin >> x;

    while (sz(d) && d.front() <= x - 1000) {
      d.pop_front();
    }

    d.push_back(x);
    mx = max(mx, sz(d));
  }


  cout << mx / k + (mx % k != 0);
}