#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> DP(10);
    DP[0] = "{}";

    rep(i, 1, 10) {
        DP[i] += '{';

        rep(j, 0, i) {
            DP[i] += DP[j];
            if (j + 1 != i) {
                DP[i] += ',';
            }
        }

        DP[i] += '}';
    }

    cout << DP[n];
    return 0;
}