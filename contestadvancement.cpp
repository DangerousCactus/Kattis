#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k, c;
  cin >> n >> k >> c;

  queue<pii> backlog;
  map<int, int> m;
  vector<pii> out;

  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;

    if (m[b] == c) {
      backlog.emplace(i, a);
    } else {
      m[b]++;
      out.emplace_back(i, a);
    }
  }

  while(sz(backlog)){
    out.push_back(backlog.front());
    backlog.pop();
  }

  out.resize(k);
  sort(all(out));

  for(auto & [a, b] : out){
    cout << b << '\n';
  }
}