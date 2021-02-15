#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  while (a != 0 || b != 0 || c != 0 || d != 0) {
    
    int total = 720;

    if (a < b) {
      total += 9 * (40 - (b - a));
    } else {
      total += 9 * (a - b);
    }

    total += 360;

    if (b < c) {
      total += 9 * (c - b);
    } else {
      total += 9 * (40 - (b - c));
    }

    if (c < d) {
      total += 9 * (40 - (d - c));
    } else {
      total += 9 * (c - d);
    }

    cout << total << "\n";
    cin >> a >> b >> c >> d;
  }
  return 0;
}