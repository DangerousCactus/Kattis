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

vector<cd> a(pow(2, 21), 0), b(pow(2, 21), 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  vector<cd>::iterator farthestB = b.end();
  rep(i, 0, s.size()) {
    if (s[i] == 'A')
      a[i] = 1;
    else {
      b[i] = 1;
      farthestB = b.begin() + i;
    }
  }

  int dist = distance(b.begin(), farthestB) + 1;
  reverse(b.begin(), farthestB + 1);
  //rotate(b.begin(), b.end() - dist + 1, b.end());

  fft(a, false);
  fft(b, false);
  rep(i, 0, a.size()) a[i] *= b[i];
  fft(a, true);

  rep(i, dist, s.size() + dist - 1){
    cout << (int)round(a[i].real()) << '\n';
  }
  return 0;
}