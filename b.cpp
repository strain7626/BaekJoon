#include <bits/stdc++.h>

using namespace std;
using ll=long long;

void solve() {
    ll p,q,sum,n,m;cin>>p>>q;
    sum=2*p+4*q+1;
    for(n=1;(2*n+1)*(2*n+1)<=sum;n++) {
        if(sum%(2*n+1)) continue;
        ll m=(sum/(2*n+1)-1)/2;
        if(m*(n+1)>=q&&n*(m+1)>=q) {cout<<n<<' '<<m<<'\n';return;}
    }

    cout<<"-1\n";
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--)solve();
}