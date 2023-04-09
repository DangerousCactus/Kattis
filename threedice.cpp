#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m[26] = {0};

void mu(int a, int b) {
  m[a] |= (1 << b);
  m[b] |= (1 << a);
}

vi l;
void solve(int a, int ma, int b, int mb, int c, int mc, int i) {
  if (i >= sz(l)) {
    int used = a | b | c;
    int n = 0;

    for (auto &&x : {a, b, c}) {
      int z = 0;

      rep(j, 0, 26) {
        if (x & (1 << j)) {
          cout << (char)('a' + j);
          z++;
        }
      }

      while (z < 6) {
        if (!(used & (1 << n))) {
          cout << (char)('a' + n);
          z++;
        }
        n++;
      }

      cout << ' ';
    }

    exit(0);
  }

  if (!(ma & (1 << l[i])) && __builtin_popcount(a) < 6) {
    solve(a | (1 << l[i]), ma | m[l[i]], b, mb, c, mc, i + 1);
  }

  if (!(mb & (1 << l[i])) && __builtin_popcount(b) < 6) {
    solve(a, ma, b | (1 << l[i]), mb | m[l[i]], c, mc, i + 1);
  }

  if (!(mc & (1 << l[i])) && __builtin_popcount(c) < 6) {
    solve(a, ma, b, mb, c | (1 << l[i]), mc | m[l[i]], i + 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> w(n);
  set<int> s;

  for (auto &&x : w) {
    cin >> x;
    for (auto &&c : x)
      if (s.insert(c - 'a').second)
        l.push_back(c - 'a');

    mu(x[0] - 'a', x[1] - 'a');
    mu(x[0] - 'a', x[2] - 'a');
    mu(x[1] - 'a', x[2] - 'a');
  }

  rep(i, 0, 26) {
    if (m[i] & (1 << i)) {
      cout << 0;
      return 0;
    }
  }

  if (sz(s) > 18) {
    cout << 0;
    return 0;
  }

  solve(1 << l[0], m[l[0]], 1 << l[1], m[l[1]], 1 << l[2], m[l[2]], 3);

  cout << 0;
  return 0;
}