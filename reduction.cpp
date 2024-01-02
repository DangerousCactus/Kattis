#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  rep(z, 1, t + 1) {
    int n, m, l;
    cin >> n >> m >> l;

    set<pair<int, string>> s;

    rep(i, 0, l) {
      string name;
      int a, b;
      cin >> ws;
      getline(cin, name, ':');
      char c;
      cin >> a >> c >> b;

      int cost = 0;
      int curr = n;

      while (n > m) {
        int next = curr / 2 + curr % 2;

        if (curr - next < m) {
          break;
        } else {
          if (next * a < b) {
            break;
          } else {
            curr /= 2;
            cost += b;
          }
        }
      }

      cost += (curr - m) * a;
      s.insert({cost, name});
    }

    cout << "Case " << z << endl;
    for(auto && x : s){
      cout << x.second << ' ' << x.first << endl;
    }
  }

  return 0;
}