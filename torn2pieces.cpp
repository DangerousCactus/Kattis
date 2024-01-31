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

  int n;
  cin >> n >> ws;

  map<string, set<string>> m;
  rep(i, 0, n) {
    string s;
    getline(cin, s);
    stringstream ss(s);

    string source;
    ss >> source;

    while (ss >> s) {
      m[source].insert(s);
      m[s].insert(source);
    }
  }

  string source, dest;
  cin >> source >> dest;

  map<string, string> parent;

  queue<string> q;
  parent[dest] = "";
  q.push(dest);

  while (sz(q)) {
    auto z = q.front();
    q.pop();

    if (z == source) {
      while (parent.count(z)) {
        cout << z << ' ';
        z = parent[z];
      }

      exit(0);
    }

    for (auto &x: m[z]) {
      if (!parent.count(x)) {
        parent[x] = z;
        q.push(x);
      }
    }
  }

  cout << "no route found";
}