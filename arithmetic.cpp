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

  string s, buffer("EZPZ");
  cin >> s;

  int o;
  cout << uppercase << hex;

  stringstream ss(s);

  if (s.size() % 4 != 0) {
    ss.read(&buffer[0], s.size() % 4);
    cout << stoi(buffer, nullptr, 8);
  }

  while (ss.peek() != EOF) {
    ss.read(&buffer[0], 4);
    cout << setfill('0') << setw(3) << stoi(buffer, nullptr, 8);
  }
  return 0;
}