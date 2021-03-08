#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int nums[3];
  cin >> nums[0] >> nums[1] >> nums[2];

  sort(nums, nums + 3);

  rep(i, 0, 3){
    char c;
    cin >> c;

    int a = c - 'A';

    cout << nums[a] << ' ';
  }
  return 0;
}