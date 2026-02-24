#include <bits/stdc++.h>
#define MOD 1000000007
#define MXN 1000000

using namespace std;
using ll=long long;

ll N,M,K,A[MXN+1],seg[4*MXN];

ll init(ll n,ll s,ll e) {
    if(s==e) return seg[n]=A[s];
    return seg[n]=init(n*2,s,(s+e)/2)*init(n*2+1,(s+e)/2+1,e)%MOD;
}
ll update(ll n,ll s,ll e,ll idx, ll val) {
    if(idx<s||e<idx) return seg[n];
    if(s==e) return seg[n]=val;
    return seg[n]=update(n*2,s,(s+e)/2,idx,val)*update(n*2+1,(s+e)/2+1,e,idx,val)%MOD;    
}
ll query(ll n,ll s,ll e,ll l,ll r) {
    if(r<s||e<l) return 1;
    if(l<=s&&e<=r) return seg[n];
    return query(n*2,s,(s+e)/2,l,r)*query(n*2+1,(s+e)/2+1,e,l,r)%MOD;    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) cin>>A[i];
    init(1,1,N);
    for(int i=0;i<M+K;i++) {
        int a,b,c;cin>>a>>b>>c;
        if(a==1) update(1,1,N,b,c);
        else cout<<query(1,1,N,b,c)<<'\n';
    }
}