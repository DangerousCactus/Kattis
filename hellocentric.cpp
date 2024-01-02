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

    int a, b;
    int t = 1;
    while (cin >> a >> b) {
        int c = 0;
        while (a != 0 || b != 0) {
            a = (a + 1) % 365;
            b = (b + 1) % 687;
            c++;
        }
        cout << "Case " << t++ << ": " << c << endl;
    }

    return 0;
}