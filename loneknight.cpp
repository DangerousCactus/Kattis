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

const vector<pii> jumps{{1, -2}, {1, 2},  {-1, 2},  {-1, -2},
                        {2, 1},  {2, -1}, {-2, -1}, {-2, 1}};

const int INF = 1 << 30;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vi xb(n), yb(n);
  rep(i, 0, n) {
    cin >> xb[i] >> yb[i];
  }

  xb.push_back(INF);
  xb.push_back(-INF);
  yb.push_back(INF);
  yb.push_back(-INF);

  sort(all(xb));
  sort(all(yb));

  xb.erase(unique(all(xb)), xb.end());
  yb.erase(unique(all(yb)), yb.end());

  const int PS = 4;

  auto getComp = [&](int i, int j, int x, int y) -> int {
    int comp = i * sz(yb) + j;
    return PS * PS * comp + PS * x + y;
  };

  UF uf(PS * PS * sz(xb) * sz(yb));

  rep(i, 0, sz(xb)) rep(j, 0, sz(yb)) {
    rep(xc, 0, min(4, xb[i + 1] - xb[i] - 1)) {
      rep(yc, 0, min(4, yb[j + 1] - yb[j] - 1)) {
        pii curr{xb[i] + 1 + xc, yb[j] + 1 + yc};

        // for each corner, simulate all 8 jumps
        for (auto& [dx2, dy2] : jumps) {
          pii link = {curr.first + dx2, curr.second + dy2};
          pii lid;

          if (link.first == xb[i] || link.second == yb[j]) {
            continue;
          }

          if (i < sz(xb) && link.first == xb[i + 1]) {
            continue;
          }

          if (j < sz(yb) && link.second == yb[j + 1]) {
            continue;
          }

          if (i > 0 && link.first == xb[i - 1]) {
            continue;
          }

          if (j > 0 && link.second == yb[j - 1]) {
            continue;
          }

          if (link.first > xb[i] && link.first < xb[i + 1]) {
            lid.first = i;
          } else if (link.first > xb[i + 1]) {
            if (i + 2 < sz(xb) && link.first != xb[i + 2]) {
              lid.first = i + 1;
            } else {
              continue;
            }
          } else if (link.first < xb[i]) {
            if (i > 0 && link.first < xb[i]) {
              lid.first = i - 1;
            } else {
              continue;
            }
          }

          if (link.second > yb[j] && link.second < yb[j + 1]) {
            lid.second = j;
          } else if (link.second > yb[j + 1]) {
            if (j + 2 < sz(yb) && link.second != yb[j + 2]) {
              lid.second = j + 1;
            } else {
              continue;
            }
          } else if (link.second < yb[j]) {
            if (j > 0 && link.second < yb[j]) {
              lid.second = j - 1;
            } else {
              continue;
            }
          }

          auto compa = getComp(i, j, xc, yc);
          auto compb = getComp(lid.first, lid.second,
                               (link.first - xb[lid.first] - 1) % 4,
                               (link.second - yb[lid.second] - 1) % 4);

          uf.join(compa, compb);
        }
      }
    }
  }

  while (q--) {
    pii a, b;
    cin >> a.first >> a.second >> b.first >> b.second;

    auto aidx = distance(xb.begin(), lower_bound(all(xb), a.first)) - 1;
    auto bidx = distance(xb.begin(), lower_bound(all(xb), b.first)) - 1;
    auto aidy = distance(yb.begin(), lower_bound(all(yb), a.second)) - 1;
    auto bidy = distance(yb.begin(), lower_bound(all(yb), b.second)) - 1;

    auto aid = getComp(aidx, aidy, (a.first - xb[aidx] - 1) % 4,
                       (a.second - yb[aidy] - 1) % 4);
    auto bid = getComp(bidx, bidy, (b.first - xb[bidx] - 1) % 4,
                       (b.second - yb[bidy] - 1) % 4);

    if (aid == bid) {
      cout << (uf.size(aid) > 1) << '\n';
    } else {
      cout << (uf.find(aid) == uf.find(bid)) << '\n';
    }
  }
}