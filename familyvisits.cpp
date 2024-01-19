#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MESS_MAX = 1000 * 1000 + 7;
const int MESS_SENTINEL = 1007;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, d;
  cin >> n >> d;
  vi messes(n), cleans(n);
  vector<bool> visits(MESS_SENTINEL);

  rep(i, 0, n) {
    cin >> messes[i] >> cleans[i];
  }

  rep(i, 0, d) {
    int x;
    cin >> x;
    visits[x - 1] = true;
  }

  vi best(MESS_MAX, MESS_SENTINEL);
  best[0] = 0;

  int messCul = 1;

  rep(i, 0, n) {
    vi nextBest(MESS_MAX, MESS_SENTINEL);

    messCul += messes[i];
    rep(j, 0, messCul) { // for each mess
      if (best[j] == MESS_SENTINEL) {
        continue;
      }

      // update mess
      // choose not to clean
      nextBest[j + messes[i]] = min(nextBest[j + messes[i]], best[j]);

      // choose to clean
      nextBest[max(0, j + messes[i] - cleans[i])] = min(nextBest[max(0, j + messes[i] - cleans[i])], best[j] + 1);
    }

    // if it's a visit day, nuke all but nextBest[0]
    if (visits[i]) {
      if (nextBest[0] == MESS_SENTINEL) {
        cout << -1;
        exit(0);
      }

      fill(all(best), MESS_SENTINEL);
      best[0] = nextBest[0];
      messCul = 1;
      continue;
    }

    swap(best, nextBest);
  }

  cout << *min_element(all(best));

}