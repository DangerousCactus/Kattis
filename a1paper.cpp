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

  int smallest;
  cin >> smallest;

  int papers[31];

  rep(i, 2, smallest + 1) cin >> papers[i];

  stack<int> sheets;
  ll needed = 2;
  int index = 2;

  while (needed > 0 && index <= smallest) {
    if (papers[index] >= needed) {
      sheets.push(needed);
      needed = 0;
    } else {
      sheets.push(papers[index]);
      needed -= papers[index];
    }
    needed *= 2;
    index++;
  }

  if (needed != 0) {
    cout << "impossible";
  } else {
    index--;
    long double tape = 0;
    while (!sheets.empty()) {
      auto temp = sheets.top();
      sheets.pop();

      tape += pow(2, (2 * index - 1) / (-4.0L)) * (temp / 2);
      
      if(!sheets.empty()){
        auto t = sheets.top();
        sheets.pop();

        sheets.push(t + temp / 2);
      }
      
      index--;
    }
    cout.precision(10);
    cout << tape;
  }

  return 0;
}