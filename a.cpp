#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=2e5+1;

ll N,K,A[MXN];

bool check(ll m) {
    ll cnt=0,k=K;
    for(int i=1;i<=N;i++) {
        if(m<=A[i]) continue;
        if(k<(m-A[i]+i-1)/i) return 0;
        k-=(m-A[i]+i-1)/i;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>A[i];

    ll l=0,r=2e18;
    while(l<r) {
        ll m=l+(r-l+1)/2;
        if(check(m)) l=m;
        else r=m-1;
    }
    cout<<l;
}