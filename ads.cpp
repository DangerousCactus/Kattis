#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 207;

char board[MAXN][MAXN];
int group[MAXN][MAXN] = {0};

int gr = 1;
map<int, pii> st;
map<int, pii> ed;

void markAds(int hmin, int hmax, int wmin, int wmax, int g) {
  rep(i, hmin, hmax) rep(j, wmin, wmax) {
    if (group[i][j] == 0) {
      if (board[i][j] == '+') {
        int hmm = i, wmm = j;

        while (wmm < wmax && board[i][wmm] == '+')
          wmm++;

        while (hmm < hmax && board[hmm][j] == '+')
          hmm++;

        gr++;
        rep(k, i, hmm) group[k][j] = group[k][wmm - 1] = gr;
        rep(k, j, wmm) group[i][k] = group[hmm - 1][k] = gr;

        st[gr] = {i, j};
        ed[gr] = {hmm, wmm};

        markAds(i + 1, hmm - 1, j + 1, wmm - 1, gr);
      } else {
        group[i][j] = g;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int h, w;
  string s;
  getline(cin, s);
  stringstream ss(s);

  ss >> h >> w;

  rep(i, 0, h) rep(j, 0, w) {
    board[i][j] = ' ';
    group[i][j] = 0;
  }

  rep(i, 0, h) {
    char c;
    getline(cin, s);
    ss = stringstream(s);

    int j = 0;
    while (ss.get(c)) {
      board[i][j++] = c;
    }
  }

  // mark ad regions
  markAds(0, h, 0, w, gr);

  rep(i, 0, h) rep(j, 0, w) {
    char curr = board[i][j];
    if (group[i][j] != 1 &&
        !(isalnum(curr) || curr == '?' || curr == '!' || curr == ',' ||
          curr == '.' || curr == ' ' || curr == '+')) {

      int tgt = group[i][j];

      rep(i2, st[tgt].first, ed[tgt].first)
          rep(j2, st[tgt].second, ed[tgt].second) board[i2][j2] = ' ';
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) { cout << board[i][j]; }
    cout << endl;
  }
  return 0;
}