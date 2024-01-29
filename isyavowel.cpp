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
  int y = 0, v = 0;
  const string vowels = "aeiou";

  char c;
  while (cin >> c) {
    if (c == 'y') {
      y++;
    }

    v += count(all(vowels), c);
  }

  cout << v << ' ' << v + y;
}