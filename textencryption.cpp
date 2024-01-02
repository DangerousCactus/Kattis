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

  int n;
  cin >> n;

  while (n) {
    string s;
    cin >> ws;
    getline(cin, s);

    string y;
    for (auto&& x : s) {
      if (x != ' ') {
        y.push_back(toupper(x));
      }
    }

    s = y;
    string out;
    out.resize(sz(s));

    int idxs = 0, idx = 0;
    for (auto&& x : s) {
      if (idx >= sz(s)) {
        idx = ++idxs;
      }

      out[idx] = x;
      idx += n;
    }

    cout << out << endl;

    cin >> n;
  }

  return 0;
}