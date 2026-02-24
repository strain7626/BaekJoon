#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll EEA(ll a,ll b,ll &x,ll &y) {
    ll g=a;x=1,y=0;
    if(b) g=EEA(b,a%b,y,x),y-=a/b*x;
    return g;
}

ll inv(ll a,ll mod) {
    ll x,y;
    if(EEA(a,mod,x,y)!=1) return -1;
    return (x%mod+mod)%mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll N,A;cin>>N>>A;
    cout<<(A==0?0:N-A)<<' '<<inv(A,N);
}