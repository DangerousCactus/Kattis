#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

char p[5000015];
char t[5000015];

int main() {
  int sz, b;
  while (scanf("%[^\n]%n\n", p, &b) != EOF) {
    scanf("%[^\n]%n\n", t, &sz);

    rep(i, 0, sz - b + 1) if (memcmp(p, t + i, b) == 0) printf("%d ", i);

    printf("\n");
  }
  return 0;
}