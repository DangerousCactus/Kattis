#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int total = 0;
  string in;
  cin >> in;

  stringstream s(in);

  int a, b;
  char c;
  while (s >> a) {
    s >> c;
    if (c == '-') {
      s >> b;
      total += b - a;
      s >> c;
    }
    total += 1;
  }

  cout << total;
  return 0;
}