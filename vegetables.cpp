#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct vegetable {
  long double s;
  int cuts = 1;

  vegetable(long double s1, int c) : s(s1), cuts(c) {}
};

bool Compare(vegetable a, vegetable b) { return a.s / a.cuts < b.s / b.cuts; }

int main() {
  cin.tie(0)->sync_with_stdio(0);

  long double t, m;
  int n;

  cin >> t >> n;

  priority_queue<vegetable, vector<vegetable>, decltype(&Compare)> pq(Compare);

  long double mn = 1E7;

  rep(i, 0, n) {
    cin >> m;
    pq.emplace(m, 1);
    mn = min(mn, m);
  }

  int cuts = 0;
  while (mn / (pq.top().s / pq.top().cuts) < t) {
    auto z = pq.top();
    pq.pop();

    pq.emplace(z.s, z.cuts + 1);
    mn = min(mn, z.s / (z.cuts + 1));
    cuts++;
  }

  cout << cuts;

  return 0;
}