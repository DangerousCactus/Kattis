#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mex(set<int> &nums) {
  int i = 0;
  for (auto &x: nums) {
    if (x != i) {
      return i;
    }
    i++;
  }

  return sz(nums);
}

int DP[31][31][31];

int nimber(int a, int b, int c) {
  if (a * b * c == 0) {
    return 0;
  }

  vi nums{a, b, c};
  sort(all(nums));

  a = nums[0], b = nums[1], c = nums[2];
  if (DP[a][b][c] != -1) {
    return DP[a][b][c];
  }

  set<int> poss;
  rep(i, 0, a / 2 + 1) {
    rep(j, 0, b / 2 + 1) {
      rep(k, 0, c / 2 + 1) {
        poss.insert(
                nimber(i, j, k) ^
                nimber(i, b - j - 1, k) ^
                nimber(i, j, c - k - 1) ^
                nimber(i, b - j - 1, c - k - 1) ^
                nimber(a - i - 1, j, k) ^
                nimber(a - i - 1, b - j - 1, k) ^
                nimber(a - i - 1, j, c - k - 1) ^
                nimber(a - i - 1, b - j - 1, c - k - 1)
        );
      }
    }
  }

  return DP[a][b][c] = mex(poss);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  rep(i, 0, 31) {
    rep(j, 0, 31) {
      rep(k, 0, 31) {
        DP[i][j][k] = -1;
      }
    }
  }

  string s;
  cin >> s;

  int n;
  cin >> n;

  int ans = 0;
  rep(i, 0, n) {
    int a, b, c;
    cin >> a >> b >> c;
    ans ^= nimber(a, b, c);
  }

  if (ans == 0) {
    if (s == "RUBEN") {
      cout << "ALBERT";
    } else if (s == "ALBERT") {
      cout << "RUBEN";
    }
  } else {
    cout << s;
  }

  return 0;
}