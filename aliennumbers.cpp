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

  int t;
  cin >> t;

  rep(tt, 1, t + 1) {
    string anum, source, target;
    cin >> anum >> source >> target;

    int sb = source.size(), tb = target.size();

    ll num = 0;
    rep(i, 0, sz(anum)) {
      num += pow(sb, i) * source.find(anum[sz(anum) - 1 - i]);
    }

    string out = "";

    while (num) {
      int idx = num % tb;
      out.push_back(target[idx]);
      num -= idx;

      num /= tb;
    }

    reverse(all(out));

    cout << "Case #" << tt << ": " << out << endl;
  }

  return 0;
}