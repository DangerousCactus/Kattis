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

  while (t--) {
    string a, b;
    cin >> a >> b;

    unordered_set<char> have(all(a));
    bool valid = true;
    for (auto &c : b) {
      if (have.find(c) == have.end()) {
        valid = false;
        break;
      }
    }

    cout << (valid ? "YES\n" : "NO\n");
  }
}