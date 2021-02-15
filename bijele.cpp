#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x,i = 0;
  int vals[6] = {1, 1, 2, 2, 2, 8};

  while (i < 6) {
      cin >> x;
      cout << vals[i++] - x << " ";
  }

  return 0;
}