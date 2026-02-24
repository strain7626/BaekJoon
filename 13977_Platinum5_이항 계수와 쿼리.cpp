#include <bits/stdc++.h>
#define MOD 1000000007
#define MXN 4000000

using namespace std;
using ll = long long;

ll M,N,K,fact[MXN+1]={1};

ll EEA(ll a,ll b,ll &x,ll &y) {
    ll g=a;x=1,y=0;
    if(b) g=EEA(b,a%b,y,x),y-=a/b*x;
    return g;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=1;i<=MXN;i++) fact[i]=fact[i-1]*i%MOD;

    cin>>M;while(M--) {
        cin>>N>>K;
        ll x,y;
        EEA(fact[N-K]*fact[K]%MOD,MOD,x,y);
        cout<<(x*fact[N]%MOD+MOD)%MOD<<'\n';
    }
}