#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  double a, b;
  int n;
  vector<pdd> v;
  vi out, indices;

  while (cin >> a >> b) {
    cin >> n;
    v.resize(n);
    indices.resize(n);
    iota(all(indices), 0);
    out.clear();

    for (auto&& x : v)
      cin >> x.first >> x.second;

    sort(all(indices), [&](int a, int b) { return v[a] < v[b]; });

    double sofar = a;
    int idx = 0;
    int best = -1;

    while (sofar < b || out.empty()) {
      best = -1;
      while (idx < v.size() && v[indices[idx]].first <= sofar) {
        if (best == -1 || v[indices[idx]].second > v[best].second)
          best = indices[idx];
        ++idx;
      }

      if (best == -1)
        break;

      sofar = v[best].second;
      out.pb(best);
    }

    if (sofar < b || out.empty())
      cout << "impossible\n";
    else {
      cout << out.size() << '\n';
      for (auto&& x : out)
        cout << x << ' ';
      cout << '\n';
    }
  }

  return 0;
}