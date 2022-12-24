#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  unordered_map<string, int> cat;
  unordered_map<int, string> catName;
  unordered_map<int, pair<set<int>::iterator, int>> catLoc;

  set<int> sickness[101];

  int n, c, i;
  std::unordered_map<int, std::pair<std::set<int>::iterator, int>>::iterator l;
  string s;
  cin >> n;

  while (n--) {
    cin >> c;
    switch (c) {
    case 0:
      cin >> s >> i;
      cat[s] = n;
      catName[n] = s;
      catLoc[n] = make_pair(sickness[i].insert(n).first, i);
      break;
    case 1:
      cin >> s >> i;
      l = catLoc.find(cat[s]);
      sickness[l->second.second].erase(l->second.first);
      i += l->second.second;
      catLoc[cat[s]] = make_pair(sickness[i].insert(cat[s]).first, i);
      break;
    case 2:
      cin >> s;
      l = catLoc.find(cat[s]);
      sickness[l->second.second].erase(l->second.first);
      catLoc.erase(l);
      break;
    case 3: // loop over all lists
      if (catLoc.size()) {
        int m = 100;
        while (true) {
          if (sickness[m].size() == 0) {
            m--;
            continue;
          }

          cout << catName[*(sickness[m].rbegin())] << '\n';
          break;
        }
      } else {
        cout << "The clinic is empty\n";
      }
      break;
    }
  }

  return 0;
}