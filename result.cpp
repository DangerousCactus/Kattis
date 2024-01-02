#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll DP[100][100];
bool calcd[100][100];

vector<ll> nums;
vector<bool> ops; // + is false, * is true

ll smin(int a, int b) {
  if (calcd[a][b])
    return DP[a][b];

  calcd[a][b] = true;

  if (a == b)
    return DP[a][b] = nums[a];

  DP[a][b] = ULLONG_MAX;
  rep(i, a, b){
    DP[a][b] = min(DP[a][b], ops[i] ? smin(a, i) * smin(i + 1, b) : smin(a, i) + smin(i + 1, b));
  }

  return DP[a][b];
}

ll smax(int a, int b) {
  if (calcd[a][b])
    return DP[a][b];

  calcd[a][b] = true;

  if (a == b)
    return DP[a][b] = nums[a];

  DP[a][b] = 0;
  rep(i, a, b){
    DP[a][b] = max(DP[a][b], ops[i] ? smax(a, i) * smax(i + 1, b) : smax(a, i) + smax(i + 1, b));
  }

  return DP[a][b];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  while (s != "END") {
    int n;
    char c;

    nums.clear();
    ops.clear();
    memset(calcd, false, 100 * 100);

    stringstream ss(s);

    ss >> n;
    nums.push_back(n);

    while (!ss.eof()) {
      ss >> c;
      ops.push_back(c == '*');
      ss >> n;
      nums.push_back(n);
    }

    cout << smin(0, nums.size() - 1) << ' ';

    memset(calcd, false, 100 * 100);
    cout << smax(0, nums.size() - 1) << '\n';

    cin >> s;
  }

  return 0;
}