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

  int z;
  cin >> z;

  map<string, pair<string, int>> bdays;

  rep(i, 0, z) {
    string name, date;
    int priority;

    cin >> name >> priority >> date;

    if (bdays.count(date) == 0) {
      bdays[date] = mp(name, priority);
    } else {
      if (bdays[date].second < priority)
        bdays[date] = mp(name, priority);
    }
  }

  cout << bdays.size() << '\n';

  vector<string> names;
  for (auto s : bdays)
    names.pb(s.second.first);

  sort(names.begin(), names.end());
  
  for (auto s : names)
    cout << s << '\n';

  return 0;
}