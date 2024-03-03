#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 20;
constexpr int MAX_RELEVANT_PEOPLE = MAXN * MAXN;


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;

  vector<bitset<MAX_RELEVANT_PEOPLE>> engineer(m);
  int id = 0;

  rep(i, 0, n) {
    bool idSet = false;
    rep(j, 0, m) {
      char c;
      cin >> c;

      if (c == '1') {
        if (engineer[j].count() < m) {
          idSet = true;
          engineer[j].set(id);
        }
      }
    }

    id += idSet;
  }
  
  int best = m;

  rep(i, 1, 1 << m) {
    bitset<MAX_RELEVANT_PEOPLE> ct;

    rep(j, 0, m) {
      if (i & (1 << j)) {
        ct |= engineer[j];
      }
    }

    int serviceCount = __builtin_popcount(i);
    if (ct.count() < serviceCount) {
      best = min(best, serviceCount - 1);
    }
  }

  cout << best;
}