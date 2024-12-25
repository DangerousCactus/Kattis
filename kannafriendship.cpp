#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, val = 0;
  bool mset = false;
  Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of -inf
  int query(int L, int R) {
    if (R <= lo || hi <= L)
      return 0;
    if (L <= lo && hi <= R)
      return val;
    push();
    return l->query(L, R) + r->query(L, R);
  }
  void set(int L, int R) {
    if (R <= lo || hi <= L)
      return;
    if (L <= lo && hi <= R) {
      mset = true;
      val = hi - lo;
    } else {
      push(), l->set(L, R), r->set(L, R);
      val = l->val + r->val;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset)
      l->set(lo, hi), r->set(lo, hi), mset = false;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  Node tree(0, 2E9 + 1);

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int s, e;
      cin >> s >> e;
      tree.set(s, e + 1);
    } else {
      cout << tree.query(0, 2E9 + 1) << '\n';
    }
  }
}