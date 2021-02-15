#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int numCases;
  cin >> numCases;
  for (int i = 0; i < numCases; i++) {
    int numSpaces;
    cin >> numSpaces;

    int mm = 107;
    int mx = -1;

    int v;
    for(int j = 0; j < numSpaces; j++){
        cin >> v;
        mx = max(mx, v);
        mm = min(mm, v);
    }

    cout << 2 * (mx - mm) << endl;

  }
  return 0;
}