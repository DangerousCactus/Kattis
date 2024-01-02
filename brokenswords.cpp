#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, r;
  char x;
  cin >> n;

  t = r = 0;

  while (n--) {
    cin >> x;
    t += (x == '0');
    cin >> x;
    t += (x == '0');
    cin >> x;
    r += (x == '0');
    cin >> x;
    r += (x == '0');
  }

  int q = min(t >> 1, r >> 1);
  cout << q << ' ';
  t -= q << 1;
  r -= q << 1;

  cout << t << ' ' << r;

  return 0;
}