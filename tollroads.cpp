#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct RollbackUF {
  vi e;
  RollbackUF(int n) : e(n, -1) {}
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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m, q, a, b;
  cin >> n >> m >> q;

  vector<vi> e(m); // cost, a, b

  for (auto &&x : e) {
    x.resize(3);
    cin >> x[1] >> x[2] >> x[0];
    x[1]--, x[2]--;
  }

  sort(all(e));

  vector<unordered_set<int>> qidx(n);
  vector<pii> answers(q);

  rep(i, 0, q) {
    cin >> a >> b;
    qidx[a - 1].insert(i);
    qidx[b - 1].insert(i);
  }

  RollbackUF uf(n);
  int i = 0;

  while (i < m) {
    vector<pii> process; // x, c
    int cost = e[i][0];

    do {
      int a = uf.find(e[i][1]);
      int b = uf.find(e[i][2]);

      if (a == b) {
        i++; // we forgot to add this in
        continue;
      }

      uf.join(e[i][1], e[i][2]);
      int c = uf.find(e[i][1]);
      //   cout << a << ' ' << b << ' ' << c << endl;

      if (a != c) {
        if (sz(qidx[a]) > sz(qidx[c]))
          qidx[a].swap(qidx[c]);

        for (auto &&x : qidx[a]) {
          auto temp = qidx[c].insert(x);
          if (!temp.second) {
            process.emplace_back(x, c);
            qidx[c].erase(temp.first);
          }
        }
      }

      if (b != c) {
        if (sz(qidx[b]) > sz(qidx[c]))
          qidx[b].swap(qidx[c]);

        for (auto &&x : qidx[b]) {
          auto temp = qidx[c].insert(x);
          if (!temp.second) {
            process.emplace_back(x, c);
            qidx[c].erase(temp.first);
          }
        }
      }

      i++;
    } while (i < m && cost == e[i][0]);

    for (auto &&x : process) {
      answers[x.first] = {cost, uf.size(x.second)};
    }
  }

  for (auto &&x : answers)
    cout << x.first << ' ' << x.second << '\n';
}
