#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int e, f, c;
  int total = 0;
  cin >> e >> f >> c;

  int totalBottles = e + f;

  while (totalBottles >= c) {
    total += totalBottles / c;
    int n = totalBottles / c;

    totalBottles -= n * c - n;
  }

  cout << total;
  return 0;
}
