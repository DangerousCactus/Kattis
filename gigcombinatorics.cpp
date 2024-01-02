#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x)       begin(x), end(x)
#define sz(x)        (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1E9 + 7;
struct Mod {
  ll x;
  Mod(ll xx) : x(xx) {}
  Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
  Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
  Mod operator*(Mod b) { return Mod((x * b.x) % mod); }

  Mod operator^(ll e) {
    if (!e)
      return Mod(1);
    Mod r = *this ^ (e / 2);
    r = r * r;
    return e & 1 ? *this * r : r;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n;

  Mod total(0);
  Mod rC(0);
  vi ones;
  int one = 0;
  int two = 0;

  rep(i, 0, n) {
    cin >> x;
    if (x == 1) {
      ones.push_back(two);
    } else if (x == 2) {
      two++;
    } else if (x == 3) {
      // consider existing ones
      rC = rC * (Mod(2) ^ two);
      total = total + rC - one;

      // add new ones
      for (auto&& z : ones) {
        z = two - z;
        total = total + (Mod(2) ^ z) - 1;
        rC = rC + (Mod(2) ^ z);
      }

      one += sz(ones);
      ones.clear();
      two = 0;
    }
  }

  cout << total.x;
}