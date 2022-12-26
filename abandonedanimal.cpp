#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, k, m;
bool ambiguous = false;
unordered_map<string, int> mp;
vector<unordered_set<int>> inventory;
vi order;

bool solve(int store, int item) {
  if (item == m && store == n)
    return true;

  if (store == n)
    return false;

  if (item > 0 && inventory[store].count(order[item - 1]))
    ambiguous = true;

  while (item < m && inventory[store].count(order[item]))
    item++;

  return solve(store + 1, item);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  inventory.resize(n);

  string s;
  int itemIdx = 0;

  rep(i, 0, k) {
    cin >> m >> s;
    if (mp.insert(make_pair(s, itemIdx)).second)
      itemIdx++;

    inventory[m].insert(mp[s]);
  }

  cin >> m;
  order.resize(m);

  for (auto &&x : order) {
    cin >> s;
    x = mp[s];
  }

  bool answer = solve(0, 0);

  if (!answer) {
    cout << "impossible";
  } else if (!ambiguous) {
    cout << "unique";
  } else {
    cout << "ambiguous";
  }

  return 0;
}