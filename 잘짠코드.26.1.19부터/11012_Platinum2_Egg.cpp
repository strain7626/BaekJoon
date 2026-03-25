#include <bits/stdc++.h>
#define MXN 100001

using namespace std;

vector<pair<int,int>> sub[MXN],sum[MXN];

int N,M,seg[4*MXN];
vector<int> pos[MXN];

int update(int n,int s,int e,int i) {
    if(i<s||e<i) return seg[n];
    if(s==e) return ++seg[n];
    return seg[n]=update(n*2,s,(s+e)/2,i)+update(n*2+1,(s+e)/2+1,e,i);
}

int query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[n];
    return query(n*2,s,(s+e)/2,l,r)+query(n*2+1,(s+e)/2+1,e,l,r);
}

void solve() {
    for(int &i:seg) i=0; 
    for(auto &i:pos) i.clear();
    for(auto &i:sub) i.clear();
    for(auto &i:sum) i.clear();

    cin>>N>>M;
    for(int i=0,x,y;i<N;i++) cin>>x>>y,pos[x].push_back(y);
    for(int i=0,x1,x2,y1,y2;i<M;i++) cin>>x1>>x2>>y1>>y2,sub[x1].push_back({y1,y2}),sum[x2].push_back({y1,y2});

    long long ans=0;
    for(int x=0;x<MXN;x++) {
        for(auto &[y1,y2]:sub[x]) ans-=query(1,0,1e5,y1,y2);
        for(int &i:pos[x]) update(1,0,1e5,i);
        for(auto &[y1,y2]:sum[x]) ans+=query(1,0,1e5,y1,y2);
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;while(T--) solve();
}