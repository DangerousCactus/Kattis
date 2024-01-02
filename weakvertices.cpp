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
    while (cin >> n) {
        if (n == -1) {
            break;
        }

        int adj[n][n];
        rep(i, 0, n) {
            rep(j, 0, n) {
                cin >> adj[i][j];
            }
        }

        rep(i, 0, n) {
            bool found = false;
            rep(j, 0, n) {
                rep(k, 0, n) {
                    found = found || (adj[i][j] && adj[j][k] && adj[i][k]);
                }
            }

            if (!found) {
                cout << i << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}