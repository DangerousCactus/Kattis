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

    vi RAM(1000, 0);
    vi reg(10, 0);

    auto it = RAM.begin();
    while (cin >> *it++);

    int i = 0, ct = 0;
    while (true) {
        ct++;

        int x = RAM[i] / 100;
        int a = (RAM[i] / 10) % 10;
        int b = RAM[i] % 10;

        if (x == 1) { break; }
        if (x == 2) { reg[a] = b; }
        if (x == 3) { reg[a] = (reg[a] + b) % 1000; }
        if (x == 4) { reg[a] = (reg[a] * b) % 1000; }
        if (x == 5) { reg[a] = reg[b]; }
        if (x == 6) { reg[a] = (reg[a] + reg[b]) % 1000; }
        if (x == 7) { reg[a] = (reg[a] * reg[b]) % 1000; }
        if (x == 8) { reg[a] = RAM[reg[b]]; }
        if (x == 9) { RAM[reg[b]] = reg[a]; }
        if (x == 0) {
            if (reg[b] != 0) {
                i = reg[a];
                continue;
            }
        }

        i++;


    }

    cout << ct;

    return 0;
}