#include <bits/stdc++.h>
using namespace std;
#define rep(totalN, a, b) for (int totalN = a; totalN < (b); ++totalN)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// min possible = (n - 1) / n = 1 - 1/n
// max possible = (n - 1) / 2

const int NMAX = 1E6;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, b;
  char c;
  cin >> a >> c >> b;

  rep(totalN, 1, NMAX + 1) {
    if ((a * totalN) % b) {
      continue;
    }

    int tgt = (a * totalN) / b;

    if (totalN - 1 <= tgt && tgt <= totalN * (totalN - 1LL) / 2) {
      rep(seqN, 1, totalN + 1) {  // nodes dedicated to 0+1..
        int poss = seqN * (seqN - 1LL) / 2 + (totalN - seqN) * (seqN - 1);
        if (poss < tgt) {
          continue;
        }

        cout << totalN << ' ' << totalN - 1 << '\n';

        // main chain
        rep(k, 1, seqN) {
          cout << k << ' ' << k + 1 << '\n';
        }

        tgt -= seqN * (seqN - 1LL) / 2;
        tgt -= (totalN - seqN);  // tax

        rep(k, seqN, totalN) {
          if (tgt - (seqN - 1) >= 0) {
            tgt -= (seqN - 1);
            cout << seqN << ' ' << k + 1 << '\n';
          } else {
            cout << tgt + 1 << ' ' << k + 1 << '\n';
            tgt = 0;
          }
        }

        exit(0);
      }
    }
  }

  cout << "impossible";
}