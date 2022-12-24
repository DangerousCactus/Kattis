#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, t, idx, i;
  ll total;
  set<int> vis;
  cin >> N >> t;

  vi A(N);
  for (auto &&x : A)
    cin >> x;

  switch (t) {
  case 1:
    cout << 7;
    break;

  case 2:
    if (A[0] > A[1])
      cout << "Bigger";
    if (A[0] == A[1])
      cout << "Equal";
    if (A[0] < A[1])
      cout << "Smaller";
    break;

  case 3:
    sort(A.begin(), A.begin() + 3);
    cout << A[1];
    break;

  case 4:
    cout << accumulate(A.begin(), A.end(), (ll)0);
    break;

  case 5:
    total = 0;
    for (auto &&x : A)
      if (x % 2 == 0)
        total += x;

    cout << total;
    break;

  case 6:
    for (auto &&x : A)
      cout << (char)(x % 26 + 'a');
    break;

  case 7:
    idx = 0;

    while (true) {
      idx = A[idx];

      if (vis.count(idx)) {
        cout << "Cyclic";
        break;
      }

      vis.insert(idx);

      if (idx < 0 || idx >= A.size()) {
        cout << "Out";
        break;
      }
      if (idx == A.size() - 1) {
        cout << "Done";
        break;
      }
    }
    break;
  }

  return 0;
}