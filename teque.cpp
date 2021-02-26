#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define rdi(x) \
  int x;       \
  cin >> x;
#define rdrp(x) \
  rdi(x);       \
  for (; x > 0; x--)
#define pb(x)    push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  deque<int> d1;
  deque<int> d2;

  string o;
  int i;

  rdrp(numOps) {
    cin >> o >> i;

    if (o == "push_back") {
      d2.pb(i);
    } else if (o == "push_front") {
      d1.push_front(i);
    } else if (o == "push_middle") {
      d2.push_front(i);
    } else {
      if (i < d1.size()) {
        cout << d1[i] << '\n';
      } else {
        cout << d2[i - d1.size()] << '\n';
      }
    }

    if(d1.size() > d2.size() + 1){
      d2.push_front(d1.back());
      d1.pop_back();
    }else if(d2.size() > d1.size()){
      d1.pb(d2.front());
      d2.pop_front();
    }
  }

  return 0;
}