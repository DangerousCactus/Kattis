#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii; // warning

set<pii> intervals; // [inclusive, exclusive)

set<pii>::iterator addInterval(set<pii> &is, ll L, ll R) {
  if (L == R)
    return is.end();
  auto it = is.lower_bound({L, R}), before = it;
  while (it != is.end() && it->first <= R) {
    R = max(R, it->second);
    before = it = is.erase(it);
  }
  if (it != is.begin() && (--it)->second >= L) {
    L = min(L, it->first);
    R = max(R, it->second);
    is.erase(it);
  }
  return is.insert(before, {L, R});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k, t1, t2;
  cin >> n >> k >> t1 >> t2;

  vector<ll> m(n);
  vector<pair<ll, ll>> sun(k);

  for (auto &&x : m)
    cin >> x;

  for (auto &&x : sun)
    cin >> x.first >> x.second;

  for (auto &&meas : m) {
    for (auto &&s : sun) {
      addInterval(intervals, s.first - meas, s.second - meas);
    }
  }

  auto start = intervals.begin();
  ll nw = 0;
  while (start != intervals.end() && start->second <= t1)
    start++;

  while (start != intervals.end() && start->first < t2) {
    nw += min(t2, start->second) - max(t1, start->first);
    start++;
  }

  cout << fixed << setprecision(18) << (t2 - t1 - nw) / ((long double)(t2 - t1));

  return 0;
}