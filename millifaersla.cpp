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

  vector<pair<int, string>> v;
  int a, b, c;
  cin >> a >> b >> c;
  v.emplace_back(a, "Monnei");
  v.emplace_back(b, "Fjee");
  v.emplace_back(c, "Dolladollabilljoll");

  cout << min_element(all(v))->second;
}