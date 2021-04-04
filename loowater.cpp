#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  while (n != 0) {
    priority_queue<int, vi, greater<int>> dragons;
    priority_queue<int, vi, greater<int>> knights;

    int temp, cost = 0;
    rep(i, 0, n) {
      cin >> temp;
      dragons.push(temp);
    }

    rep(i, 0, m) {
      cin >> temp;
      knights.push(temp);
    }

    while (!dragons.empty()) {
      while (!knights.empty() && knights.top() < dragons.top())
        knights.pop();

      if (knights.empty())
        break;

      cost += knights.top();
      knights.pop();
      dragons.pop();
    }

    if (!dragons.empty())
      cout << "Loowater is doomed!";
    else
      cout << cost;
    cout << '\n';

    cin >> n >> m;
  }
  return 0;
}