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

  int c, d;
  cin >> c >> d;

  vi fizz, buzz;
  rep(i, c, d + 1) {
    string s;
    cin >> s;

    if (s == "Fizz") {
      fizz.push_back(i);
    } else if (s == "Buzz") {
      buzz.push_back(i);
    } else if (s == "FizzBuzz") {
      fizz.push_back(i);
      buzz.push_back(i);
    }
  }

  for (const auto& ar : {fizz, buzz}) {
    if (!sz(ar)) {
      cout << 999999;
    } else if (sz(ar) > 1) {
      cout << ar[1] - ar[0];
    } else {
      cout << ar[0];
    }

    cout << ' ';
  }
}