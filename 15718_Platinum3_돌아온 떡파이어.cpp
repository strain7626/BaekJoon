#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll EEA(ll a,ll b,ll &x, ll &y) {
    ll g=a;x=1,y=0;
    if(b) g=EEA(b,a%b,y,x),y-=a/b*x;
    return g;
}

ll CRT(vector<ll> &rem,vector<ll> &mod) {
    ll tot=1,sum=0,x,y;for(ll i:mod) tot*=i;
    for(int i=0;i<rem.size();i++) {
        ll sub=tot/mod[i];
        EEA(sub,mod[i],x,y);
        ll inv=(x%mod[i]+mod[i])%mod[i];               
        sum=(sum+rem[i]*sub%tot*inv)%tot;
    }
    return sum;
}

ll lkt(ll N,ll K,ll mod,ll *fac) {
    ll res=1,x,y;
    while(N||K) {
        ll n=N%mod,k=K%mod;N/=mod,K/=mod;
        if(n<k) return 0;
        EEA(fac[n-k]*fac[k]%mod,mod,x,y);
        res=res*(x*fac[n]%mod+mod)%mod;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll f1[98]={1},f2[1032]={1};
    for(int i=1;i<=97;i++) f1[i]=f1[i-1]*i%97;
    for(int i=1;i<=1031;i++) f2[i]=f2[i-1]*i%1031;

    int T;cin>>T;while(T--) {
        ll N,M;cin>>N>>M;
        if(!N) {
            cout<<(M==1)<<'\n';
            continue;
        }
        if(N<M-1||M==1) {
            cout<<0<<'\n';
            continue;
        }

        N-=1,M-=2;
        ll x1=lkt(N,M,97,f1),x2=lkt(N,M,1031,f2);
        vector<ll> rem={x1,x2},mod={97,1031};
        cout<<CRT(rem,mod)<<'\n';
    }
}