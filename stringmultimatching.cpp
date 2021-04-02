#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vi> counts;
vector<int> words;

struct TrieNode {
  array<int, 96> links;
  vi sp;
  int failure = 0;
  int dict = -1;

  TrieNode() { fill(all(links), -1); }
  int& operator[](int i) { return links[i - 32]; }

  void log(int idx) {
    for (auto x : sp)
      counts[x].pb(idx - words[x] + 1);
  }
};

array<TrieNode, 100007> TNL;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (scanf("%d\n", &n) != EOF) {
    counts.clear();
    counts.resize(n);
    words.assign(n, 0);

    TNL[0] = TrieNode();

    // Make Trie
    int curr, idx = 1, w = 0;

    for (auto& word : words) {
      curr = 0;

      for (char c = getchar(); c != '\n'; c = getchar()) {
        ++word;
        if (TNL[curr][c] == -1) {
          TNL[idx] = TrieNode();
          TNL[curr][c] = idx++;
        }
        curr = TNL[curr][c];
      }
      TNL[curr].sp.pb(w++);
    }

    queue<int> q;

    rep(i, 32, 128) {
      if (TNL[0][i] == -1)
        TNL[0][i] = 0;
      else
        q.push(TNL[0][i]);
    }

    while (!q.empty()) {
      int f = q.front();
      q.pop();

      rep(i, 32, 128) {
        if (TNL[f][i] != -1) {
          auto child = TNL[f][i];
          q.push(child);

          // Generate Failure Links
          curr = TNL[f].failure;
          while (TNL[curr][i] == -1)
            curr = TNL[curr].failure;

          TNL[child].failure = TNL[curr][i];

          // Generate Dict Links
          TNL[child].dict = TNL[curr][i];
          while (TNL[child].dict != -1 && TNL[TNL[child].dict].sp.empty())
            TNL[child].dict = TNL[TNL[child].dict].dict;
        }
      }
    }

    // Traverse
    curr = 0;
    idx = 0;
    int tempDict;

    for (char c = getchar(); c != '\n'; c = getchar()) {
      while (TNL[curr][c] == -1)
        curr = TNL[curr].failure;

      curr = TNL[curr][c];

      if (!TNL[curr].sp.empty())
        TNL[curr].log(idx);

      tempDict = TNL[curr].dict;

      while (tempDict != -1) {
        TNL[tempDict].log(idx);
        tempDict = TNL[tempDict].dict;
      }

      idx++;
    }

    for (auto const& i : counts) {
      for (auto const& j : i)
        printf("%d ", j);
      printf("\n");
    }
  }
  return 0;
}