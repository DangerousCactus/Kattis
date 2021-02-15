#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pair<double, double>> m;

  int sz;
  cin >> sz;

  char in;

  for (double y = 0; y < sz; y++) {
    for (double x = 0; x < sz; x++) {
      cin >> in;
      if (in != '.') {
        m.push_back(make_pair(x, y));
      }
    }
  }
  int count = 0;
  for (auto i = 0; i < m.size(); i++) {
    for (auto j = i + 1; j < m.size(); j++) {
      double slope = -1;

      if ((m[j].first - m[i].first) != 0) {
        slope = abs((m[j].second - m[i].second) / (m[j].first - m[i].first));
      }

      for (auto k = j + 1; k < m.size(); k++) {
        if (m[k].first == m[i].first || m[k].first == m[j].first) {
          if (slope == -1) {
            count++;
            // cout << "COORDS: " << m[i].first << "," << m[i].second << " "
            //      << m[j].first << "," << m[j].second << " " << m[k].first << ","
            //      << m[k].second << " " << endl;
          }

        } else if (abs((m[k].second - m[i].second) /
                       (m[k].first - m[i].first)) == slope &&
                   abs((m[k].second - m[j].second) /
                       (m[k].first - m[j].first)) == slope) {
          count++;
          // cout << "COORDS: " << m[i].first << "," << m[i].second << " "
          //      << m[j].first << "," << m[j].second << " " << m[k].first << ","
          //      << m[k].second << " " << endl;
        }
      }
    }
  }
  cout << count;
  return 0;
}