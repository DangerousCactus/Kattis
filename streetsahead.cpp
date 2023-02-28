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

  int n, q;
  cin >> n >> q;

  unordered_map<string, int> m;
  string s, a, b;

  while (n--) {
    cin >> s;
    m[s] = m.size();
  }

  while (q--) {
    cin >> a >> b;
    cout << abs(m[b] - m[a]) - 1 << endl;
  }

  return 0;
}