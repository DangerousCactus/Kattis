#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  vi books;
  books.resize(n);
  rep(i, 0, n) cin >> books[i];

  sort(books.begin(), books.end());

  ll total = 0;

  for (int i = n - 1; i >= 0; i = i - 3) {
    total += books[i];
  }

  for (int i = n - 2; i >= 0; i = i - 3) {
    total += books[i];
  }

  cout << total;

  return 0;
}