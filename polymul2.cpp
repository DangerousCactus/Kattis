#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> cd;

const double PI = acos(-1);

void fft(vector<cd>& v, bool inv) {
  int n = v.size();
  if (n == 1)
    return;

  vector<cd> evens(n / 2), odds(n / 2);

  rep(i, 0, n / 2) {
    evens[i] = v[2 * i];
    odds[i] = v[2 * i + 1];
  }

  fft(odds, inv);
  fft(evens, inv);

  double angle = 2 * PI / n;
  cd ang(1, 0), step(cos(angle), sin(angle));

  if (inv)
    step = conj(step);

  rep(k, 0, n / 2) {
    v[k] = evens[k] + ang * odds[k];
    v[k + n / 2] = evens[k] - ang * odds[k];
    ang *= step;

    if (inv) {
      v[k] /= 2;
      v[k + n / 2] /= 2;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, sz1, sz2, temp;
  cin >> t;

  vector<cd> a(pow(2, 18), cd(0, 0)), b(pow(2, 18), cd(0, 0));

  cin >> sz1;
  rep(j, 0, sz1 + 1) {
    cin >> temp;
    a[j] = cd(temp, 0);
  }

  cin >> sz2;
  rep(j, 0, sz2 + 1) {
    cin >> temp;
    b[j] = cd(temp, 0);
  }

  fft(a, false);
  fft(b, false);

  rep(j, 0, pow(2, 18)) a[j] *= b[j];

  fft(a, true);

  int idx = sz1 + sz2;
  while (idx >= 0 && round(a[idx].real()) == 0)
    --idx;

  cout << idx << endl;
  rep(i, 0, idx + 1) cout << ((int)round(a[i].real())) << ' ';
  return 0;
}