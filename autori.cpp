#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string in;
  cin >> in;

  bool printNext = true;
  for (int i = 0; i < in.length(); i++) {
    if (printNext) {
      cout << in[i];
      printNext = false;
    } else if (in[i] == '-')
      printNext = true;
  }

  return 0;
}