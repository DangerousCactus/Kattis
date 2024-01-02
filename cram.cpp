#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct SuffixArray {
    vi sa, lcp, rank;

    SuffixArray(string &s, int lim = 256) { // or basic string<int>
        int n = sz(s) + 1, k = 0, a, b;
        vi x(all(s) + 1), y(n), ws(max(n, lim));
        sa = lcp = rank = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i - 1], b = sa[i], x[b] =
                        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        rep(i, 1, n) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k];
        k++);
    }
};

template<typename T> struct rmq {
    vector<T> v;
    int n; static const int b = 30;
    vector<int> mask, t;

    int op(int x, int y) { return v[x] < v[y] ? x : y; }
    int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
    int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
    rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
        for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
            at = (at<<1)&((1<<b)-1);
            while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
        }
        for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
        for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
                t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
    }
    T query(int l, int r) { // inclusive
        if (r-l+1 <= b) return v[small(r, r-l+1)];
        int ans = op(small(l+b-1), small(r));
        int x = l/b+1, y = r/b-1;
        if (x <= y) {
            int j = msb(y-x+1);
            ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
        }
        return v[ans];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    getline(cin, s);
//    cin >> s;

    auto [sa, lcp,rank] = SuffixArray(s);
    rmq saRMQ(lcp);

    set<int> seen{-1, 999999};
    vi furthestJump(sz(s), 0);
//    iota(all(furthestEnd), 0);

    rep(i, 0, sz(s)){
        auto currRank = rank[i];
        auto nextRank = *seen.upper_bound(currRank);
        auto prevRank = *prev(seen.upper_bound(currRank));

        if(nextRank != 999999){
            furthestJump[i] = max(furthestJump[i], saRMQ.query(currRank + 1, nextRank));
        }

        if(prevRank != -1){
            furthestJump[i] = max(furthestJump[i], saRMQ.query(prevRank + 1, currRank));
        }

        seen.insert(currRank);
    }

    vi DP(sz(s) + 1, INT_MAX);
    DP[0] = 0;

//    for(auto & x : furthestJump){
//        cout << x << ' ';
//    }
//    cout << endl;

    rep(i, 0, sz(s)){
        DP[furthestJump[i] + i] = min(DP[furthestJump[i] + i], DP[i] + 3);
        DP[i + 1] = min(DP[i + 1], DP[i] + 1);
    }

//    for(auto & x : DP){
//        cout << x << ' ';
//    }
//    cout << endl;

    cout << DP[sz(s)];


}