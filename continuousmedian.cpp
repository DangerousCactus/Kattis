#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define rdi(x) \
  int x;       \
  cin >> x;
#define rdrp(x)  rdi(x) for (; x > 0; x--)
#define pb(x)    push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  rdrp(T) {
    int temp;
    ll total = 0;

    // size of minheap >= size of maxheap
    priority_queue<int> maxHeap;                    // small values
    priority_queue<int, vi, greater<int>> minHeap;  // big values
    bool both = false;
    rdrp(N) {
      cin >> temp;

      if (minHeap.empty() || temp >= minHeap.top())
        minHeap.push(temp);
      else
        maxHeap.push(temp);

      if (minHeap.size() < maxHeap.size()) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }

      if (maxHeap.size() + 1 < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }

      if (both)
        total += (maxHeap.top() + minHeap.top()) / 2;
      else
        total += minHeap.top();

      both = !both;
    }

    cout << total << '\n';
  }

  return 0;
}