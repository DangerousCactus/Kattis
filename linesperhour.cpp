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

  int n, lph;
  cin >> n >> lph;
  lph *= 5;

  vi lines(n);
  for (auto &x: lines) {
    cin >> x;
  }

  sort(all(lines));
  int ct = 0, sum = 0;
  while (ct < n && sum + lines[ct] <= lph) {
    sum += lines[ct++];
  }

  cout << ct;
}