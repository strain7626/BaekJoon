#include <bits/stdc++.h>

using namespace std;

int N,M,A[100001],seg[400001];
bool lzy[400001];

void propagate(int n,int s,int e) {
    if(!lzy[n]) return;
    seg[n]=(e-s+1)-seg[n];
    if(s!=e) lzy[n*2]^=lzy[n],lzy[n*2+1]^=lzy[n];
    lzy[n]=0;
}

int update(int n,int s,int e,int l,int r) {
    propagate(n,s,e);
    if(r<s||e<l) return seg[n];
    if(l<=s&&e<=r) {
        lzy[n]^=1;
        propagate(n,s,e);
        return seg[n];
    }
    return seg[n]=update(n*2,s,(s+e)/2,l,r)+update(n*2+1,(s+e)/2+1,e,l,r);
}

int query(int n,int s,int e,int l,int r) {
    propagate(n,s,e);
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[n];
    return query(n*2,s,(s+e)/2,l,r)+query(n*2+1,(s+e)/2+1,e,l,r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;

    while(M--) {
        int O,S,T;cin>>O>>S>>T;
        if(O) cout<<query(1,1,N,S,T)<<'\n';
        else update(1,1,N,S,T);
    }
}