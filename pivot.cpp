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

    int n;
    cin >> n;

    vi nums(n);
    set<int> s;
    int ans = 0;

    for (auto &x: nums) {
        cin >> x;
        s.insert(x);
    }

    auto sorted = nums;
    sort(all(sorted));

    int mx = -1;

    rep(i, 0, n) {
        s.erase(nums[i]);
        mx = max(mx, nums[i]);

        if(mx <= nums[i] && s.lower_bound(nums[i]) == s.begin()){
            ans++;
        }
    }

    cout << ans;
}