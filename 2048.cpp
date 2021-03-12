#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vector<int> doRow(list<int> d) {  // default to left
  d.remove(0);
  vector<int> out;

  while (!d.empty()) {
    int curr = d.front();
    d.pop_front();

    if (!d.empty() && d.front() == curr) {
      out.push_back(curr * 2);
      d.pop_front();
    } else {
      out.push_back(curr);
    }
  }

  while (out.size() < 4) {
    out.push_back(0);
  }

  return out;
}

vii transpose(vii v) {
  rep(i, 0, v.size()) {
    rep(j, i + 1, v.size()) { swap(v[i][j], v[j][i]); }
  }

  return v;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int in;
  int board[4][4] = {0};
  int newBoard[4][4] = {0};

  rep(y, 0, 4) {
    rep(x, 0, 4) {
      cin >> in;
      board[y][x] = in;
    }
  }

  int dir;
  cin >> dir;
  vector<vector<int>> vd;

  if (dir == 0) {  // left
    rep(i, 0, 4) vd.push_back(doRow(list<int>(&board[i][0], &board[i][4])));

  } else if (dir == 3) {  // down
    list<int> temp;
    rep(i, 0, 4) {
      temp.clear();
      rep(j, 0, 4) { temp.push_back(board[3 - j][i]); }
      vector<int> out = doRow(temp);
      reverse(out.begin(), out.end());
      vd.push_back(out);
    }

    vd = transpose(vd);

  } else if (dir == 2) {  // right
    rep(i, 0, 4) {
      list<int> temp(&board[i][0], &board[i][4]);
      temp.reverse();
      vector<int> out = doRow(temp);
      reverse(out.begin(), out.end());
      vd.push_back(out);
    }

  } else if (dir == 1) {  // up
    list<int> temp;
    rep(i, 0, 4) {
      temp.clear();
      rep(j, 0, 4) { temp.push_back(board[j][i]); }

      vd.push_back(doRow(temp));
    }

    vd = transpose(vd);
  }

  for (auto a : vd) {
    for (auto b : a) {
      cout << b << ' ';
    }
    cout << '\n';
  }

  return 0;
}