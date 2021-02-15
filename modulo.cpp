#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vi test;
  int tmp;
  for (int i = 0; i < 10; i++) {
    cin >> tmp;
    test.push_back(tmp);
  }

  set<int> s;
  for (int num : test) {
		s.insert(num % 42);
  }

	cout << s.size();

  return 0;
}