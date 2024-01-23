#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1E9 + 7; // change to something e lse
struct Mod {
    ll x;

    Mod(ll xx) : x(xx) {}

    Mod() : x(0) {}

    Mod operator+(const Mod b) const { return {(x + b.x) % mod}; }

    Mod operator-(const Mod b) const { return {(x - b.x + mod) % mod}; }

    Mod operator*(const Mod b) const { return {(x * b.x) % mod}; }

    Mod operator^(ll e) {
      if (!e) return {1};
      Mod r = *this ^ (e / 2);
      r = r * r;
      return e & 1 ? *this * r : r;
    }
};

template<class T, int N>
struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};

    M operator*(const M &m) const {
      M a;
      rep(i, 0, N) rep(j, 0, N)rep(k, 0, N) a.d[i][j] = a.d[i][j] + d[i][k] * m.d[k][j];
      return a;
    }

    vector<T> operator*(const vector<T> &vec) const {
      vector<T> ret(N);
      rep(i, 0, N) rep(j, 0, N) ret[i] = ret[i] + d[i][j] * vec[j];
      return ret;
    }

    M operator^(ll p) const {
      assert(p >= 0);
      M a, b(*this);
      rep(i, 0, N) a.d[i][i] = 1;
      while (p) {
        if (p & 1) a = a * b;
        b = b * b;
        p >>= 1;
      }
      return a;
    }
};


int main() {
  cin.tie(0)->sync_with_stdio(0);

  ll a, b;
  cin >> a >> b;

  if (a == 1) {
    cout << (b <= 9);
    exit(0);
  }

  vi offsets;
  int offset = b % 25;

  for (auto &x: vi{0, 25, 50, 75}) {
    x = (x + offset) % 100;
    if (x / 10 != x % 10) {
      offsets.push_back(x);
    }
  }

  // generate transition matrix
  Matrix<Mod, 90> transition;
  // each row is result, each column is contribution

  // /9 -> last digit used, %9-> modulus
  rep(r, 0, 90) {
    rep(c, 0, 90) {
      if (r / 9 == c / 9) {
        continue; // repeated digit
      }

      transition.d[r][c] = (((c % 9 + r / 9) % 9) == r % 9);
    }
  }

//  rep(i, 0, 90){
//    cout << i << ": ";
//    rep(j, 0, 90){
//      if(transition.d[i][j].x == 1) {
//        cout << j << ' ';
//      }
//    }
//    cout << endl;
//  }

  // raise it to the (a-2)th power
  transition = transition ^ (a - 2);

  Mod out;

  for (auto &x: offsets) {
    vector<Mod> base(90);
    base[(x / 10) * 9 + (x % 9)] = 1;

    auto baseT = transition * base;

    rep(i, 0, 90) {
      if (i % 9 == b % 9 && i / 9 != 0) {
        out = out + baseT[i];
      }
    }
  }

  cout << out.x;
}