#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int numCases;
  cin >> numCases;
  getchar();  // discard \n
  rep(cs, 0, numCases) {
    list<char> s;
    auto iter = s.end();
    
    string st;
    getline(cin, st);

    for(auto c : st) {
      if (c == ']') {
        iter = s.end();
      } else if (c == '[') {
        iter = s.begin();
      } else if (c == '<') {
        if (iter != s.begin()) {
          iter--;
          auto before = --iter;
          s.erase(++iter);
          iter = ++before;
        }
      } else {
        s.insert(iter, c);
      }
    }

    for (auto ch : s) {
      cout << ch;
    }

    cout << '\n';
  }

  return 0;
}