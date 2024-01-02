#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void print(__int128_t x) {
  stack<int> out;
  while (x) {
    out.push(x % 10);
    x /= 10;
  }

  if (sz(out)) {
    while (sz(out)) {
      cout << out.top();
      out.pop();
    }
  } else {
    cout << '0';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<__int128_t, __int128_t>>> e(n);
  vector<__int128_t> mats(n, 0);
  vector<int> in(n, 0);

  for (auto &&x : mats) {
    int z;
    cin >> z;
    x = z;
  }

  rep(i, 0, m) {
    int a, b, c;
    cin >> a >> b >> c;

    e[b].emplace_back(a, c);
    in[a]++;
  }

  queue<int> q;

  rep(i, 0, n) {
    if (!in[i]) {
      q.push(i);
    }
  }

  while (sz(q)) {
    auto z = q.front();
    q.pop();

    for (auto &&x : e[z]) {
      mats[x.first] += mats[z] * x.second;
      if (--in[x.first] == 0) {
        q.push(x.first);
      }
    }
  }

  for (auto &&x : mats) {
    print(x);
    cout << ' ';
  }

  return 0;
}