#include <bits/stdc++.h>
#define MXN 75000
#define x first
#define y second

using namespace std;
using pii=pair<int,int>;

int N,seg[MXN*4],idx[MXN];
pii pos[MXN];

int update(int n,int s,int e,int i) {
    if(i<s||e<i) return seg[n];
    if(s==e) return seg[n]=1;
    return seg[n]=update(n*2,s,(s+e)/2,i)+update(n*2+1,(s+e)/2+1,e,i);
}

int query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[n];
    return query(n*2,s,(s+e)/2,l,r)+query(n*2+1,(s+e)/2+1,e,l,r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;while(T--) {
        cin>>N;
        for(int i=0;i<N;i++) idx[i]=i;
        for(int i=1;i<N*4;i++) seg[i]=0;
        
        for(int i=0;i<N;i++) cin>>pos[i].x>>pos[i].y;
        sort(pos,pos+N,[](pii a,pii b){return (a.x==b.x?a.y>b.y:a.x<b.x);});        
        sort(idx,idx+N,[&](int a,int b){return (pos[a].y==pos[b].y?pos[a].x<pos[b].x:pos[a].y>pos[b].y);});

        long long ans=0;
        for(int i=0;i<N;i++) ans+=query(1,0,N-1,0,idx[i]),update(1,0,N-1,idx[i]);
        cout<<ans<<'\n';
    }
}