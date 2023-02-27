#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi cars;
map<vi, int> m;

int solve(vi q, int idx) {
  if (idx == sz(cars))
    return 0;

  sort(all(q));

  if (m.find(q) != m.end())
    return m[q];

  int b = 0;

  if (q[0] >= cars[idx])
    b = max(b, 1 + solve(vi{q[0] - cars[idx] - 1, q[1], q[2], q[3]}, idx + 1));
  if (q[1] >= cars[idx])
    b = max(b, 1 + solve(vi{q[0], q[1] - cars[idx] - 1, q[2], q[3]}, idx + 1));
  if (q[2] >= cars[idx])
    b = max(b, 1 + solve(vi{q[0], q[1], q[2] - cars[idx] - 1, q[3]}, idx + 1));
  if (q[3] >= cars[idx])
    b = max(b, 1 + solve(vi{q[0], q[1], q[2], q[3] - cars[idx] - 1}, idx + 1));

  return m[q] = b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, l;
  cin >> n >> l;

  cars.resize(n);

  for (auto &&x : cars)
    cin >> x;

  cout << solve(vi{l, l, l, l}, 0);

  return 0;
}