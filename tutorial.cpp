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

    ll m, n, t;
    cin >> m >> n >> t;

    if (t == 1) {
        ll temp = 1;
        rep(i, 1, n + 1){
            temp *= i;
            if(temp > m){
                cout << "TLE";
                return 0;
            }
        }

        if(temp <= m){
            cout << "AC";
        }
    }
    if (t == 2) {
        cout << ((long double)log2(m) >= n ? "AC" : "TLE");
    }
    if (t == 3) {
        cout << (n * n <= m && n * n * n <= m && n * n * n * n <= m ? "AC" : "TLE");
    }
    if (t == 4) {
        cout << (n * n <= m && n * n * n <= m ? "AC" : "TLE");
    }
    if (t == 5) {
        cout << (n * n <= m ? "AC" : "TLE");
    }
    if (t == 6) {
        cout << (n * (long double)log2(n) <= m ? "AC" : "TLE");
    }
    if (t == 7) {
        cout << (n <= m ? "AC" : "TLE");
    }
}