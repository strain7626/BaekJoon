#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll EEA(ll a,ll b,ll &x,ll &y) {
    ll g=a;x=1,y=0;
    if(b) g=EEA(b,a%b,y,x),y-=(a/b)*x;
    return g;
}

ll mod(ll a,ll mod) {
    return (a%mod+mod)%mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll M,seed,X1,X2,x,y,a,c;cin>>M>>seed>>X1>>X2;
    EEA(mod(seed-X1,M),M,x,y);
    a=mod(x*(X1-X2),M);
    c=mod(X1-a*seed,M);
    cout<<a<<' '<<c;
}