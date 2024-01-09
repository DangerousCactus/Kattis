#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TMAX = 86400;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  // time, type, person

  vector<vi> times;

  rep(i, 0, n) {
    int m;
    cin >> m;

    rep(j, 0, m) {
      int s, e;
      cin >> s >> e;

      times.push_back({s, 0, i});
      times.push_back({e, 1, i});
    }
  }

  sort(all(times));

  int mx = 0;
  int tmx = 0;

  int ct = 0;
  int last = 0;

  int idx = 0;

  while (idx < sz(times)) {
    int time = times[idx][0], type = times[idx][1], person = times[idx][2];

    if (type == 1) {
      if (ct > mx) {
        mx = ct;
        tmx = time - last + 1;
      } else if (ct == mx) {
        tmx += time - last + 1;
      }
      ct--;
    } else {
      ct++;
    }

    last = time;
    idx++;
  }

  if (ct > mx) {
    mx = ct;
    tmx = TMAX - last + 1;
  } else if (ct == mx) {
    tmx += TMAX - last + 1;
  }

  cout << mx << '\n' << tmx;
}