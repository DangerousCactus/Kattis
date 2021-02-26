#include <bits/stdc++.h>
#define rep(a) for (int tmpl = 0; tmpl < a; tmpl++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int numCases;
  cin >> numCases;

  rep(numCases) {
    int numCuts;
    string in;
    bool front = true;
    cin >> numCuts >> in;

    while (numCuts-- > 0 && in.length() > 3) {
      int toRemove = in.length() / 4;

      if (front) {
        in.erase(0, toRemove);
      } else {
        in.erase(in.length() - toRemove, toRemove);
      }

      front = !front;
    }
    cout << in << '\n';
  }

  return 0;
}