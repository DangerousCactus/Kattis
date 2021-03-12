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
  int z, t;
  cin >> z;
  rep(i, 0, z) {
    cin >> t;
    vi grades;
    double sum = 0;
    rep(j, 0, t) {
      int temp;
      cin >> temp;
      grades.pb(temp);
      sum += temp;
    }

    double average = sum / t;
    double aa = 0;
    rep(j, 0, t) if (grades[j] > average) aa++;

    cout.precision(3);
    cout << fixed << 100*aa/t << '%' << '\n';
  }
  return 0;
}