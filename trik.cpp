#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  char c;
  vi arr{1, 0, 0};
  while (cin >> c) {
    switch (c) {
      case 'A':
        swap(arr[0], arr[1]);
        break;
      case 'B':
        swap(arr[2], arr[1]);
        break;
      case 'C':
        swap(arr[0], arr[2]);
        break;

      default:
        break;
    }
  }

  if (arr[0] == 1) {
    cout << 1;
  } else if (arr[1] == 1) {
    cout << 2;
  } else {
    cout << 3;
  }

  return 0;
}