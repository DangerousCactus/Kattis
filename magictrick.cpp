#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int oldSize = s.size();

  sort(s.begin(), s.end());
  auto end = unique(s.begin(), s.end());
  cout << (oldSize == distance(s.begin(), end));

  return 0;
}