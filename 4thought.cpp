#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

map<int, string> answers;

int generate(string s) {
  deque<int> nums{4, 4, 4, 4};
  if (s[0] == '*') {
    nums.pop_front();
    nums[0] = 16;
  }
  if (s[0] == '/') {
    nums.pop_front();
    nums[0] = 1;
  }

  if (s[1] == '*') {
    int first = nums[nums.size() - 3];
    int second = nums[nums.size() - 2];
    nums.erase(nums.end() - 3);
    nums[nums.size() - 2] = first * second;
  }
  if (s[1] == '/') {
    int first = nums[nums.size() - 3];
    int second = nums[nums.size() - 2];
    nums.erase(nums.end() - 3);
    nums[nums.size() - 2] = first / second;
  }

  if (s[2] == '*') {
    int second = nums.back();
    nums.pop_back();
    int first = nums.back();
    nums.pop_back();
    nums.pb(first * second);
  }
  if (s[2] == '/') {
    int second = nums.back();
    nums.pop_back();
    int first = nums.back();
    nums.pop_back();
    nums.pb(first / second);
  }

  int index = 0;
  while (nums.size() > 1) {
    while (s[index] == '*' || s[index] == '/') {
      index++;
    }

    int first = nums.front();
    nums.pop_front();
    int second = nums.front();
    nums.pop_front();

    if (s[index] == '+')
      nums.push_front(first + second);
    else if (s[index] == '-')
      nums.push_front(first - second);
    index++;
  }

  answers[nums.front()] = s;
  return nums.front();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int z;
  cin >> z;

  string ops[] = {"+", "-", "*", "/"};

  for (auto i : ops) {
    for (auto j : ops) {
      for (auto k : ops) {
        generate(i + j + k);
      }
    }
  }

  rep(i, 0, z) {
    int temp;
    cin >> temp;
    if (answers.count(temp) == 0) {
      cout << "no solution\n";
    } else {
      rep(j, 0, 3) { cout << "4 " << answers[temp][j] << " "; }
      cout << "4 = " << temp << '\n';
    }
  }
  return 0;
}