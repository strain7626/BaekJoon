#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,M,A[100001],seg[400000],lzy[400000];

ll init(int n,int s,int e) {
    if(s==e) return seg[n]=A[s];
    return seg[n]=init(n*2,s,(s+e)/2)+init(n*2+1,(s+e)/2+1,e);
}
void propagate(int n,int s,int e) {
    if(!lzy[n]) return;
    seg[n]+=lzy[n]*(e-s+1);
    if(s!=e) lzy[n*2]+=lzy[n],lzy[n*2+1]+=lzy[n];
    lzy[n]=0;
}

ll update(int n,int s,int e,int l,int r,int d) {
    propagate(n,s,e);
    if(r<s||e<l) return seg[n];
    if(l<=s&&e<=r) {
        lzy[n]+=d;
        propagate(n,s,e);
        return seg[n];
    }
    return seg[n]=update(n*2,s,(s+e)/2,l,r,d)+update(n*2+1,(s+e)/2+1,e,l,r,d);
}

ll query(int n,int s,int e,int idx) {
    propagate(n,s,e);
    if(s==e) return seg[n];
    return (idx<=(s+e)/2?query(n*2,s,(s+e)/2,idx):query(n*2+1,(s+e)/2+1,e,idx));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    init(1,1,N);

    cin>>M;
    while(M--) {
        int O;cin>>O;
        if(O==1) {
            int i,j,k;cin>>i>>j>>k;
            update(1,1,N,i,j,k);
        } else {
            int x;cin>>x;
            cout<<query(1,1,N,x)<<'\n';
        }
    }
}