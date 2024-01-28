#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int digits(int x){
  if(x == 0){
    return 0;
  }
  return digits(x / 10) + 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    set<int> out;

    rep(i, 1, sz(s) + 1){
      int first = stoi(s.substr(0, i));
      if(first >= 100000){
        break;
      }

      int curr = first + 1;
      int missing = 0;

      int idx = i;
      bool fail = false;

      while(idx + digits(curr) <= sz(s)){
        if(s.substr(idx, digits(curr)) == to_string(curr)){
          idx += digits(curr++);
        }else{
          if(missing){
            fail = true;
            break;
          }
          missing = curr++;
        }
      }

      if(fail || (idx != sz(s)) || curr > 100000){
        continue;
      }

      if(!missing){
        if(first - 1 >= 1){
          out.insert(first - 1);
        }

        if(curr <= 99999){
          out.insert(curr);
        }
      }else{
        out.insert(missing);
      }
    }

    cout << sz(out) << '\n';
    for(auto & x: out){
      cout << x << ' ';
    }
    cout << '\n';

  }
}