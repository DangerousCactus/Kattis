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

    vi box(6);
    int h1, h2;

    for (auto &x: box) {
        cin >> x;
    };
    cin >> h1 >> h2;

    sort(all(box));

    do {
        if (is_sorted(box.begin(), box.begin() + 3) &&
            is_sorted(box.begin() + 3, box.end()) &&
            accumulate(box.begin(), box.begin() + 3, 0) == h2 &&
            accumulate(box.begin() + 3, box.end(), 0) == h1) {
            break;
        }
    } while (next_permutation(all(box)));

    reverse(all(box));
    for (auto &x: box) {
        cout << x << ' ';
    }
    return 0;
}