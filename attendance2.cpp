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

    deque<string> q;
    rep(i, 0, n){
        string s;
        cin >> s;

        if(s == "Present!"){
            q.pop_back();
        }else{
            q.push_back(s);
        }
    }

    if(!sz(q)){
        cout << "No Absences";
    }

    for(auto & x : q){
        cout << x << '\n';
    }

}