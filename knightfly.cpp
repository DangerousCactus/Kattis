#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> dirs{{2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
// 8 directions as given
/*
up = pos y
righ= pos x
UP
-1x +2y
+1x +2y
DOWN
-1x -2y
+1x -2y

RIGHT
+2x -1y
+2x +1y
LEFT
-2x -1y
-2x +1y
  */
vector<pii> ox, oy;
//
void processUpFirst(pii dir, pii o, queue<pii> &nq) { // move up first
  auto it = lower_bound(ox.begin(), ox.end(), o) + dir.first;

  if (it >= ox.end() || it < ox.begin() || it->first != o.first)
    return;

  o = {it->second, it->first};
  it = lower_bound(oy.begin(), oy.end(), o) + dir.second;

  if (it >= oy.end() || it < oy.begin())
    return;

  if (it->first == o.first)
    nq.push({it->second, it->first});
}

void processLeftFirst(pii dir, pii o, queue<pii> &nq) { // move left first
  auto it = lower_bound(oy.begin(), oy.end(), make_pair(o.second, o.first)) + dir.first;

  if (it >= oy.end() || it < oy.begin() || it->first != o.second)
    return;

  o = {it->second, it->first};
  it = lower_bound(ox.begin(), ox.end(), o) + dir.second;

  if (it >= ox.end() || it < ox.begin())
    return;

  if (it->first == o.first)
    nq.push(*it);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, a, b;
  cin >> n;

  pii st, e;
  set<pii> vis;

  // make sets for pairs

  cin >> st.first >> st.second >> e.first >> e.second;
  rep(i, 0, n) {
    cin >> a >> b;
    ox.emplace_back(a, b);
    oy.emplace_back(b, a);
  }

  sort(ox.begin(), ox.end());
  sort(oy.begin(), oy.end());

  int m = 0;
  queue<pii> q;
  q.push(st);

  while (q.size()) {
    queue<pii> nq;

    while (q.size()) {
      auto t = q.front();
      q.pop();

      if (t == e) {
        cout << m;
        return 0;
      }

      if (!vis.insert(t).second)
        continue;

      for (auto &&x : dirs) {
        processUpFirst(x, t, nq);
        processLeftFirst(x, t, nq);
      }
    }

    q = nq;
    m++;
  }

  cout << -1;
  return 0;
}