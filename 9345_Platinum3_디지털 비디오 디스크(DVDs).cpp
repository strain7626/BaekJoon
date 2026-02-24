#include <bits/stdc++.h>

using namespace std;

int N,K,seg[400000][2],val[100000];

void init(int n,int s,int e) {
    if(s==e) {
        seg[n][0]=seg[n][1]=val[s];
        return;
    }
    init(n*2,s,(s+e)/2);
    init(n*2+1,(s+e)/2+1,e);
    seg[n][0]=min(seg[n*2][0],seg[n*2+1][0]);
    seg[n][1]=max(seg[n*2][1],seg[n*2+1][1]);
}

void update(int n,int s,int e,int idx) {
    if(idx<s||e<idx) return;
    if(s==e) {
        seg[n][0]=seg[n][1]=val[s];
        return;
    }
    update(n*2,s,(s+e)/2,idx);
    update(n*2+1,(s+e)/2+1,e,idx);
    seg[n][0]=min(seg[n*2][0],seg[n*2+1][0]);
    seg[n][1]=max(seg[n*2][1],seg[n*2+1][1]);
}

pair<int,int> query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return {1e9,-1e9};
    if(l<=s&&e<=r) return {seg[n][0],seg[n][1]};
    auto [m1,M1]=query(n*2,s,(s+e)/2,l,r);
    auto [m2,M2]=query(n*2+1,(s+e)/2+1,e,l,r);
    return {min(m1,m2),max(M1,M2)};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;while(T--) {
        cin>>N>>K;
        for(int i=0;i<N;i++) val[i]=i;
        init(1,0,N-1);
        while(K--) {
            int Q,A,B;cin>>Q>>A>>B;
            if(Q) {
                auto [m,M]=query(1,0,N-1,A,B);
                cout<<(m==A&&M==B?"YES\n":"NO\n");
            } else {
                swap(val[A],val[B]);
                update(1,0,N-1,A);
                update(1,0,N-1,B);
            }
        }
    }
}