#include<bits/extc++.h>
#include<bits/stdc++.h>
#define y insert
using namespace std;using namespace __gnu_pbds;template<class T>using R=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;int main(){long n,o,i;cin>>n;vector<long>b(n),c(n);R<long double>t,r;map<int,int>m,v;for(i=0;i<n;i++){cin>>o;c[i]=i-t.order_of_key(2*o);m.y({o,0});t.y(++m[o]*0.00001L+o);b[i]=o;}o=0;for(i=--n;i>=0;i--){n=b[i];o+=c[i]*r.order_of_key(n/2);v.y({n,0});r.y(n-++v[n]*0.00001L);}cout<<o;return 0;}