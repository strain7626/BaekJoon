#include <bits/stdc++.h>
#define MOD 1000000007
#define MXN 1000000

using namespace std;
using pii=pair<int,int>;

int N,M,A[MXN+1];
pii seg[4*MXN];

pii init(int n,int s,int e) {
    if(s==e) return seg[n]={A[s],A[s]};
    auto [a,b]=init(n*2,s,(s+e)/2);
    auto [c,d]=init(n*2+1,(s+e)/2+1,e);
    return seg[n]={min(a,c),max(b,d)};
}
pii query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return {1e9,-1e9};
    if(l<=s&&e<=r) return seg[n];
    auto [a,b]=query(n*2,s,(s+e)/2,l,r);
    auto [c,d]=query(n*2+1,(s+e)/2+1,e,l,r);
    return {min(a,c),max(b,d)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++) cin>>A[i];
    init(1,1,N);
    for(int i=0;i<M;i++) {
        int a,b;cin>>a>>b;
        pii Q=query(1,1,N,a,b);
        cout<<Q.first<<' '<<Q.second<<'\n';
    }
}