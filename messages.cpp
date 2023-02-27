#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
  typedef uint64_t ull;
  ull x;
  H(ull x = 0) : x(x) {}
#define OP(O, A, B)                                                            \
  H operator O(H o) {                                                          \
    ull r = x;                                                                 \
    asm(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B);                        \
    return r;                                                                  \
  }
  OP(+, , "d"(o.x)) OP(*, "mul %1\n", "r"(o.x) : "rdx") H operator-(H o) {
    return *this + ~o.x;
  }
  ull get() const { return x + !~x; }
  bool operator==(H o) const { return get() == o.get(); }
  bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11 + 3; // (order ∼ 3e9 ; random a lso ok)
struct HashInterval {
  vector<H> ha, pw;
  HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
    pw[0] = 1;
    rep(i, 0, sz(str)) ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;
  }
  H hashInterval(int a, int b) { // hash [a , b)
    return ha[b] - ha[a] * pw[b - a];
  }
};
vector<H> getHashes(string &str, int length) {
  if (sz(str) < length)
    return {};
  H h = 0, pw = 1;
  rep(i, 0, length) h = h * C + str[i], pw = pw * C;
  vector<H> ret = {h};
  rep(i, length, sz(str)) {
    ret.push_back(h = h * C + str[i] - pw * str[i - length]);
  }
  return ret;
}
H hashString(string &s) {
  H h{};
  for (char c : s)
    h = h * C + c;
  return h;
}

int DP[55555];
int n;

int solve(int idx, HashInterval &h, vector<pair<string, H>> &d) {
  if (idx >= n)
    return 0;

  if (DP[idx] != -1)
    return DP[idx];

  DP[idx] = 0;

  for (auto &&x : d) {
    if (idx + sz(x.first) <= n) {
      if (h.hashInterval(idx, idx + sz(x.first)) == x.second) {
        DP[idx] = max(DP[idx], 1 + solve(idx + sz(x.first), h, d));
      }
    }
  }

  DP[idx] = max(DP[idx], solve(idx + 1, h, d));

  return DP[idx];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<pair<string, H>> dic;

  string s;
  while (cin >> s) {
    if (s == "#")
      break;

    dic.emplace_back(s, hashString(s));
  }

  string process;
  while (cin >> s) {
    if (s == "#")
      break;

    process.clear();
    process = s;

    while (process.back() != '|') {
      cin >> s;
      process += s;
    }
    process.pop_back();

    HashInterval processHash(process);

    memset(DP, -1, sizeof DP);
    n = sz(process);
    cout << solve(0, processHash, dic) << endl;
  }

  return 0;
}