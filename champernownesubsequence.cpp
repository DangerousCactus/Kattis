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

  string s;
  cin >> s >> s;

  int idx = 0;
  int nextNum = 0;

  while (idx < sz(s)) {
    string curr = to_string(++nextNum);
    for(auto & c : curr){
      if(idx < sz(s) && c == s[idx]){
        idx++;
      }
    }
  }

  cout << nextNum;
}