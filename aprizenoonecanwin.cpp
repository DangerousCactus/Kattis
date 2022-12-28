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

  int n, x, total = 1;
  cin >> n >> x;

  vi nums(n);

  for (auto &&w : nums)
    cin >> w;

  sort(all(nums));
  for (auto i = nums.begin(); i != nums.end() - 1; i++)
    total += *i + *(i + 1) <= x;

  cout << total;

  return 0;
}