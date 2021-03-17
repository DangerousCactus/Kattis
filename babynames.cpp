#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct TrieNode {
  char data;
  int countMale = 0;
  int countFemale = 0;
  int suitability = -1;  // 1: male, 2: female, -1: unassigned
  vector<TrieNode*> links = vector<TrieNode*>(26, nullptr);

  TrieNode(char d, int suit) : data(d), suitability(suit) {}
};

TrieNode* top = new TrieNode('t', -1);

void add(string s, int gs) {
  TrieNode* currNode = top;

  for (char c : s) {
    if (gs == 1)
      currNode->countMale++;
    else
      currNode->countFemale++;

    if (currNode->links[c - 'A'] == nullptr)
      currNode->links[c - 'A'] = new TrieNode(c, -1);

    currNode = currNode->links[c - 'A'];
  }

  if (gs == 1)
    currNode->countMale++;
  else
    currNode->countFemale++;

  currNode->suitability = gs;
}

void remove(string s) {
  TrieNode* currNode = top;
  stack<TrieNode*> pass;

  for (char c : s) {
    pass.push(currNode);
    currNode = currNode->links[c - 'A'];
  }
  pass.push(currNode);

  int gs = currNode->suitability;
  while (!pass.empty()) {
    currNode = pass.top();
    pass.pop();
    if (gs == 1)
      currNode->countMale--;
    else
      currNode->countFemale--;
  }
}

int sumToZ(TrieNode* root, string& start, int gs) {
  int count = 0;

  if (start.empty()) {
    if (gs == 1 || gs == 0)
      count += root->countMale;
    if (gs == 2 || gs == 0)
      count += root->countFemale;

    return count;
  }

  for (auto i = start.back() + 1; i <= 'Z'; i++) {
    if ((gs == 1 || gs == 0) && root->links[i - 'A'] != nullptr)
      count += root->links[i - 'A']->countMale;
    if ((gs == 2 || gs == 0) && root->links[i - 'A'] != nullptr)
      count += root->links[i - 'A']->countFemale;
  }

  char startTemp = start.back();
  start.pop_back();

  if (top->links[startTemp - 'A'] != nullptr)
    count += sumToZ(root->links[startTemp - 'A'], start, gs);

  return count;
}

int sumFromA(TrieNode* root, string& end, int gs) {
  if (end.empty())
    return 0;

  int count = 0;

  for (auto i = 'A'; i < end.back(); i++) {
    if ((gs == 1 || gs == 0) && root->links[i - 'A'] != nullptr)
      count += root->links[i - 'A']->countMale;
    if ((gs == 2 || gs == 0) && root->links[i - 'A'] != nullptr)
      count += root->links[i - 'A']->countFemale;
  }

  char endTemp = end.back();
  end.pop_back();

  if (root->links[endTemp - 'A'] != nullptr)
    count += sumFromA(root->links[endTemp - 'A'], end, gs);

  return count;
}

int qry(string start, string end, int gs) {
  reverse(start.begin(), start.end());
  reverse(end.begin(), end.end());

  int count = 0;

  // Between
  for (auto i = start.back() + 1; i < end.back(); i++) {
    if ((gs == 1 || gs == 0) && top->links[i - 'A'] != nullptr)
      count += top->links[i - 'A']->countMale;
    if ((gs == 2 || gs == 0) && top->links[i - 'A'] != nullptr)
      count += top->links[i - 'A']->countFemale;
  }

  char startTemp = start.back();
  start.pop_back();
  char endTemp = end.back();
  end.pop_back();

  if (top->links[startTemp - 'A'] != nullptr)
    count += sumToZ(top->links[startTemp - 'A'], start, gs);
  if (top->links[endTemp - 'A'] != nullptr)
    count += sumFromA(top->links[endTemp - 'A'], end, gs);

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int query, gs;
  string name;
  string s, e;
  cin >> query;

  while (query != 0) {
    if (query == 1) {
      cin >> name >> gs;
      add(name, gs);
    } else if (query == 2) {
      cin >> name;
      remove(name);
    } else if (query == 3) {
      cin >> s >> e >> gs;
      cout << qry(s, e, gs) << '\n';
    }

    cin >> query;
  }

  return 0;
}