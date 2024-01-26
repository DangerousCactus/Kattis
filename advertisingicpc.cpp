#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 998244353;

struct Mod {
    ll x;

    Mod(ll xx) : x(xx) {}

    Mod() : x(-1) {}

    Mod operator+(Mod b) { return Mod((x + b.x) % mod); }

    Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }

    Mod operator*(Mod b) { return Mod((x * b.x) % mod); }

    Mod operator^(ll e) {
      if (!e) return Mod(1);
      Mod r = *this ^ (e / 2);
      r = r * r;
      return e & 1 ? *this * r : r;
    }
};

Mod DP[1 << 20][70];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  map<char, int> ctoi{{'I', 1}, {'C', 2}, {'P', 3}};

  int n, m;
  cin >> n >> m;

  string g;
  rep(i, 0, n * m) {
    char c;
    cin >> c;
    g += c;
  }

  auto no = [](int x) {
      return (1 << x) - 1;
  };

  // gen good mask
  int check = (ctoi['I'] << 2) | ctoi['C'];
  check <<= 2 * m;
  check |= (ctoi['P'] << 2) | ctoi['C'];

  // gen clear mask
  int clrhi = no(2 * (m + 2));
  int clrmid = ~(no(2 * (m - 2)) << 4);


  function<Mod(int, int, int)> solve = [&](int mask, int idx, int q) {
      mask &= clrhi;
      auto& out = DP[mask][idx];

      if (out.x != -1) {
        return DP[mask][idx];
      }
      out = Mod(0);

      if ((idx - 1) % m > 0 && ((clrmid & mask) ^ check) == 0) {
        return out = Mod(3) ^ q;
      }

      if (idx < m * n) {
        if (g[idx] != '?') {
          out = out + solve((mask << 2) | ctoi[g[idx]], idx + 1, q);
        } else {
          for (auto &[k, v]: ctoi) {
            out = out + solve((mask << 2) | v, idx + 1, q - 1);
          }
        }
      }

      return out;
  };

  cout << solve(0, 0, count(all(g), '?')).x;
}