#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define rdi(x) \
  int x;       \
  cin >> x;
#define rdrp(x)  rdi(x) for (; x > 0; x--)
#define pb(x)    push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  rdi(N);
  rdi(t);

  vi nums;
  rep(a, 0, N) {
    rdi(i);
    nums.pb(i);
  }

  sort(nums.begin(), nums.end());

  switch (t) {
    case 1: {
      int i = 0;
      bool found = false;
      while (i < N && nums[i] <= 7777) {
        if (binary_search(nums.begin(), nums.end(), 7777 - nums[i]))
          found = true;
          i++;
      }
      cout << (found ? "Yes" : "No");
      break;
    }
    case 2: {
      bool unique = true;

      rep(a, 0, N - 1) {
        if (nums[a] == nums[a + 1]) {
          unique = false;
        }
      }

      cout << (unique ? "Unique" : "Contains duplicate");
      break;
    }
    case 3: {
      int found = -1;
      rep(i, 0, (N + 1) / 2) {
        if (nums[i] == nums[i + N / 2]) {
          found = nums[i];
        }
      }
      cout << found;
      break;
    }

    case 4:
      if (N % 2) {
        cout << nums[N / 2];
      } else {
        cout << nums[N / 2 - 1] << ' ' << nums[N / 2];
      }
      break;

    case 5:
      rep(a, 0, N) {
        if (nums[a] >= 100 && nums[a] <= 999) {
          cout << nums[a] << " ";
        }
      }
      break;
  }

  return 0;
}