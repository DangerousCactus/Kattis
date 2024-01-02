#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int maxN = 2000009;

int gDP[maxN];
int bgt[maxN];

int oDP[maxN];

vi coins;

int g(int i) {
  if (i < 0)
    return INT_MAX / 2;

  if (gDP[i] == -1) {
    if (i - bgt[i] >= 0)
      gDP[i] = 1 + g(i - bgt[i]);
  }

  return gDP[i];
}

int o(int i) {
  if (i < 0)
    return INT_MAX / 2;

  if (oDP[i] == -1) {
    oDP[i] = i;

    rep(j, 0, coins.size()) {
      // for (auto &&x : coins) {
      if (i - coins[j] >= 0)
        oDP[i] = min(oDP[i], 1 + o(i - coins[j]));
    }
  }
  return oDP[i];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  fill(gDP, gDP + maxN, -1);
  fill(oDP, oDP + maxN, -1);
  fill(bgt, bgt + maxN, -1);

  gDP[0] = oDP[0] = bgt[0] = 0;

  int n;
  cin >> n;

  coins.resize(n);

  for (auto &&x : coins) {
    cin >> x;
    bgt[x] = x;
  }

  for (int i = 1; i < maxN; i++) {
    if (bgt[i] == -1) {
      bgt[i] = bgt[i - 1];
    }
  }

  for (int i = 0; i < maxN; i++)
    g(i) && o(i);

  rep(i, 0, maxN) {
    if (gDP[i] != oDP[i]) {
      cout << "non-";
      break;
    }
  }

  cout << "canonical";

  return 0;
}