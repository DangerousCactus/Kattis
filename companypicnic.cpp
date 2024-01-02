#include <bits/stdc++.h>
#define rep(x, start, end) for (int x = start; x < end; x++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct emp {
  string name;
  long double speed;
  string super;

  vector<emp *> children;

  int maxTeamsBelow = 0;
  long double totalSpeedBelow = 0;

  int maxTeamsInc = 0;
  long double totalSpeedInc = 0;
};

void solve(emp *e) {
  for (auto &&x : e->children) {
    solve(x);

    // we don't pair with children
    e->maxTeamsBelow += x->maxTeamsInc;
    e->totalSpeedBelow += x->totalSpeedInc;
  }

  e->maxTeamsInc = e->maxTeamsBelow;
  e->totalSpeedInc = e->totalSpeedBelow;

  // pair with children one at a time
  for (auto &&x : e->children) {
    int tempTeams = e->maxTeamsBelow;
    tempTeams -= x->maxTeamsInc;
    tempTeams += x->maxTeamsBelow + 1;

    long double tempSpeed = e->totalSpeedBelow;
    tempSpeed -= x->totalSpeedInc;
    tempSpeed += x->totalSpeedBelow;
    tempSpeed += min(e->speed, x->speed);

    if (tempTeams > e->maxTeamsInc) {
      e->maxTeamsInc = tempTeams;
      e->totalSpeedInc = tempSpeed;
    } else if (tempTeams == e->maxTeamsInc) {
      e->totalSpeedInc = max(e->totalSpeedInc, tempSpeed);
    }
  }

  // if (e->maxTeamsInc == 0) {
  //   e->maxTeamsInc = e->maxTeamsBelow;
  //   e->totalSpeedInc = e->totalSpeedBelow;
  // }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  map<string, emp *> m;
  emp *CEO;

  rep(i, 0, n) {
    emp *x = new emp;
    cin >> x->name >> x->speed >> x->super;
    m[x->name] = x;
  }

  for (auto &&e : m) {
    auto x = e.second;
    if (x->super != "CEO") {
      m[x->super]->children.push_back(x);
    } else {
      CEO = x;
    }
  }

  solve(CEO);

  auto t = CEO;
  while (t->children.size())
    t = t->children.front();
  auto ans = m.find(t->super)->second;

  cout << CEO->maxTeamsInc << ' ' << fixed << setprecision(10);
  cout << CEO->totalSpeedInc / CEO->maxTeamsInc;

  return 0;
}