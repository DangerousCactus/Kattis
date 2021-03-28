#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

char s[100005];
int ptrs[100005];
int numq, currQ, sz;

bool lessThan(const int& first, const int& sec) {
  int res = memcmp(s + first, s + sec, sz - max(first, sec));

  if (res == 0)
    return first > sec;
  else
    return res < 0;
}

int main() {
  while (scanf("%[^\n]%n", s, &sz) != EOF) {
    scanf("%d", &numq);

    rep(i, 0, sz) ptrs[i] = i;

    sort(ptrs, ptrs + sz, lessThan);

    rep(i, 0, numq) {
      scanf("%d", &currQ);
      printf("%d ", ptrs[currQ]);
    }
    printf("%c", '\n');

    getchar();  // discard newline
  }

  return 0;
}