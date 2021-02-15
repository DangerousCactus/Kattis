#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int sze;
  scanf("%d", &sze);

  vi nums;
  int n;

  for (int i = 0; i < sze; i++) {
    scanf("%d", &n);
    nums.push_back(n);
  }

  for(auto i = nums.rbegin(); i != nums.rend(); i++){
      printf("%d\n", *i);
  }

  return 0;
}