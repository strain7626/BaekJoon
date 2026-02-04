#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,M,T[100000];

bool check(ll t) {
    ll cnt=M;
    for (int i=0;i<N;i++) {
        cnt-=t/T[i];
        if (cnt<=0) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for (int i=0;i<N;i++) cin>>T[i];

    ll l=1,r=1e18;
    while (l<r) {
        ll m=(l+r)/2;

        if (check(m)) r=m;
        else l=m+1;
    }
    cout<<l;
}