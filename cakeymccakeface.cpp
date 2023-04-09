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
  int n, m;
  cin >> n >> m;

  vi in(n), out(m);
  for (auto &&x : in)
    cin >> x;
  for (auto &&x : out)
    cin >> x;

  unordered_map<int, int> c;

  for (auto &&x : in) {
    for (auto &&y : out) {
      if (x <= y) {
        c[y - x]++;
      }
    }
  }

  pii best{0, 0};
  for (auto &&x : c) {
    if (x.second > best.second ||
        x.second == best.second && x.first < best.first) {
      best = x;
    }
  }

  cout << best.first;
}