#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char m[] = {'0', '1', '2', '5', '9', '8', '6'};

  int x;
  while (!cin.eof()) {
    string out;
    cin >> x;

    while (x > 0) {
      out += m[x % 7];
      x /= 7;
    }

    cout << out << endl;
  }

  return 0;
}

// 1 -> 1
// 2 -> 2
// 3 -> x INVALID
// 4 -> x INVALID
// 5 -> 5
// 6 -> 9
// 7 -> x INVALID
// 8 -> 8
// 9 -> 6
// 0 -> 0

// 1   2   3   4   5   6   7
// 1,  2,  5,  9,  8,  6,  01
// 11, 12, 15, 19, 18, 16, 02
