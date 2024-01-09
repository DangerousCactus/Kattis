#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string letters = "PIZA";
  string guess = "";

  int n;
  cin >> n;

  int res = 0;
  int idx = 0;

  while (true) {
    guess.push_back(letters[idx]);
    if(idx == 3 && sz(guess) < n){
      idx = 0;
      random_shuffle(all(letters));
      guess.push_back(letters[idx]);
    }

    cout << guess << endl;
    cin >> res;

    if (res == 0) {
      guess.pop_back();
      idx++;
    } else if (res == 1) {
      idx = 0;
      random_shuffle(all(letters));
    } else {
      return 0;
    }
  }
}