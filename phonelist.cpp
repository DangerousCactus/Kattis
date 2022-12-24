#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

class TrieNode {
public:
  bool isEnd = false;
  bool isUsed = false;
  vector<TrieNode *> links = vector<TrieNode *>(10, nullptr);

  TrieNode() {}
};

bool insert(TrieNode *top, string &s) {
  TrieNode *curr = top;
  bool alreadyUsed;

  for (char c : s) {
    if (curr->links[c - '0'] == nullptr)
      curr->links[c - '0'] = new TrieNode();
    curr = curr->links[c - '0'];
    
    alreadyUsed = curr->isUsed;
    curr->isUsed = true;

    if (curr->isEnd)
      return false;
  }

  curr->isEnd = true;
  return !alreadyUsed;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n;
  string s;
  cin >> t;

  while (t--) {
    cin >> n;
    bool valid = true;
    TrieNode *head = new TrieNode();
    rep(i, 0, n) {
      cin >> s;
      valid = valid && insert(head, s);
    }

    cout << (valid ? "YES" : "NO") << endl;
  }

  return 0;
}