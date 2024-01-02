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

    vector<string> out;

    string s = "aaaaaaaa";
    out.push_back(s);

    while (s[sz(s) - 5] <= 'c') {
        while (s[sz(s) - 3] != 'z') {
            while (s.back() != 'z') {
                s.back() += 1;
                out.push_back(s);
                s[sz(s) - 2] += 1;
                out.push_back(s);
            }

            s[sz(s) - 3] += 1;
            out.push_back(s);
            s[sz(s) - 4] += 1;
            out.push_back(s);

            if (s[sz(s) - 3] == 'z') {
                break;
            }

            while (s.back() != 'a') {
                s.back() -= 1;
                out.push_back(s);
                s[sz(s) - 2] -= 1;
                out.push_back(s);
            }

            s[sz(s) - 3] += 1;
            out.push_back(s);
            s[sz(s) - 4] += 1;
            out.push_back(s);
        }
        s[sz(s) - 5] += 1;
        out.push_back(s);
        s[sz(s) - 6] += 1;
        out.push_back(s);

        while (s[sz(s) - 3] != 'a') {
            while (s.back() != 'a') {
                s.back() -= 1;
                out.push_back(s);
                s[sz(s) - 2] -= 1;
                out.push_back(s);
            }

            s[sz(s) - 3] -= 1;
            out.push_back(s);
            s[sz(s) - 4] -= 1;
            out.push_back(s);

            if (s[sz(s) - 3] == 'a') {
                break;
            }

            while (s.back() != 'z') {
                s.back() += 1;
                out.push_back(s);
                s[sz(s) - 2] += 1;
                out.push_back(s);
            }

            s[sz(s) - 3] -= 1;
            out.push_back(s);
            s[sz(s) - 4] -= 1;
            out.push_back(s);
        }

        s[sz(s) - 5] += 1;
        out.push_back(s);
        s[sz(s) - 6] += 1;
        out.push_back(s);

    }

//    cout << sz(out) << endl;
    rep(i, 0, n) {
        cout << out[i] << '\n';
    }
}