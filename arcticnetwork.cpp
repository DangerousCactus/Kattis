#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : find(e[x]); }

  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

auto Compare = [](pair<double, pii> a, pair<double, pii> b) {
  return a.first < b.first;
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  while (n--) {
    int s, p;
    cin >> s >> p;

    vector<pii> pt(p);
    for (auto &&x : pt)
      cin >> x.first >> x.second;

    vector<pair<double, pii>> pq;

    rep(i, 0, p) rep(j, i + 1, p) {
      double d = hypot(pt[i].first - pt[j].first, pt[i].second - pt[j].second);
      pq.emplace_back(d, make_pair(i, j));
    }

    sort(all(pq), Compare);

    UF u(p);

    int idx = 0;
    double mx = 0;

    while (p > s) {
      auto d = pq[idx].first;
      auto sts = pq[idx].second;

      if (u.join(sts.first, sts.second)) {
        p--;
        mx = max(mx, d);
      }

      idx++;
    }

    cout << fixed << setprecision(2) << mx << endl;
  }

  return 0;
}