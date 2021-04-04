#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
  for (char c = getchar(); c != EOF; c = getchar())
    if (c == '\n' || c == ' ')
      putchar(c);
    else
      putchar(keyboard[keyboard.find(c) - 1]);

  return 0;
}
