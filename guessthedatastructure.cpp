#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; ++x)
#define pb(x)              push_back(x)
#define mp(x, y)           make_pair(x, y)
#define all(x)             x.begin(), x.end()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t, x;

  while (cin >> n) {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;

    bool isS, isQ, isPQ;
    isS = isQ = isPQ = true;

    rep(i, 0, n) {
      cin >> t >> x;

      if (t == 1) {
        s.push(x);
        q.push(x);
        pq.push(x);
      } else {
        if (s.empty()) {
          isS = isQ = isPQ = false;
          continue;
        }

        if (s.top() != x)
          isS = false;
        if (q.front() != x)
          isQ = false;
        if (pq.top() != x)
          isPQ = false;

        s.pop();
        q.pop();
        pq.pop();
      }
    }

    if ((isS && isQ) || (isQ && isPQ) || (isS && isPQ)) {
      cout << "not sure";
    } else if (!(isS || isQ || isPQ)) {
      cout << "impossible";
    } else {
      if (isS)
        cout << "stack";
      if (isQ)
        cout << "queue";
      if (isPQ)
        cout << "priority queue";
    }

    cout << '\n';
  }

  return 0;
}