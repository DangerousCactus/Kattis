#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, b = 0;
  cin >> n;

  string s;
  map<string, int> m;
  for (; i < n; ++i) {
    cin >> s;
    if (m.count(s))
      b = max(b, n - i + m[s]);
    m[s] = i;
  }
  cout << b;
}