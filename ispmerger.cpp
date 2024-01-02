#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool cp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }

  if (a.first == 1) {
    return true;
  }

  if (b.first == 1) {
    return false;
  }

  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;

  vi degmax(n);
  vector<bool> vis(n);
  vector<vi> e(n);

  priority_queue<pii, vector<pii>, function<bool(pii, pii)>> comps(
      cp); // #open ports, #deletable edges

  for (auto &&x : degmax) {
    cin >> x;
  }

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  rep(i, 0, n) {
    if (vis[i]) {
      continue;
    }

    pii temp{0, 0};
    int c = 0;

    queue<int> bfs;
    bfs.push(i);
    vis[i] = true;

    while (sz(bfs)) {
      auto z = bfs.front();
      bfs.pop();

      c++;

      temp.first += degmax[z] - sz(e[z]);
      temp.second += sz(e[z]);

      for (auto &&x : e[z]) {
        if (!vis[x]) {
          bfs.push(x);
          vis[x] = true;
        }
      }
    }

    temp.second /= 2;
    temp.second -= (c - 1);

    comps.push(temp);
  }

  int edits = 0;

  pii curr = comps.top();
  comps.pop();

  while (sz(comps)) {
    pii temp = comps.top();
    comps.pop();

    if (curr == pii{0, 0}) {
      cout << "no";
      return 0;
    }

    if (curr.first == 0) {
      curr.first += 2;
      curr.second--;
      edits++;
    }

    if (temp.first == 0) {
      if (temp.second == 0) {
        comps.emplace(1, 0);
        temp.first = 1;
      } else {
        temp.first += 2;
        temp.second--;
      }
      edits++;
    }

    edits++;
    curr.first += temp.first - 2;
    curr.second += temp.second;
  }

  cout << (edits <= k ? "yes" : "no");

  return 0;
}