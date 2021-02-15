#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int total = -1;
  int curr = -1;

  int tmp;

  for (int i = 0; i < 5; i++) {
    int t = 0;
    for (int j = 0; j < 4; j++) {
      cin >> tmp;
      t += tmp;
    }

    if (t > total) {
      total = t;
      curr = i + 1;
    }
  }

  cout << curr << " " << total;
  return 0;
}