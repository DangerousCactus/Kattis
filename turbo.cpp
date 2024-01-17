#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;

  vi index(n);
  Tree<int> tr;

  rep(i, 0, n) {
    int x;
    cin >> x;
    tr.insert(i);
    index[x - 1] = i;
  }

  int l = 0, r = n - 1;
  rep(i, 0, n) {
    int out;
    if (i % 2 == 0) {
      out = tr.order_of_key(index[l]);
      tr.erase(index[l]);
      l++;
    } else {
      out = sz(tr) - 1 - tr.order_of_key(index[r]);
      tr.erase(index[r]);
      r--;
    }

    cout << out << '\n';
  }
}