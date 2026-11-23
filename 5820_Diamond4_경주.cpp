#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=2e5+5,MXK=1e6+6;

int N,K,SZ[MXN],X[MXK],ans=1e9;
bool chk[MXN];
vector<pair<int,int>> E[MXN];

int cen(int now,int sz,int p) {
    for(auto [nxt,val]:E[now]) if(nxt!=p&&!chk[nxt]&&SZ[nxt]*2>sz) return cen(nxt,sz,now);
    return now;
}

int sz(int now,int p) {
    SZ[now]=1;
    for(auto [nxt,_val]:E[now]) if(nxt!=p&&!chk[nxt]) SZ[now]+=sz(nxt,now); 
    return SZ[now];
}

void dfs1(int now,int val,int dst,int p) {
    if(K<val) return;
    ans=min(ans,dst+X[K-val]);
    for(auto [nxt,_val]:E[now]) if(nxt!=p&&!chk[nxt]) dfs1(nxt,val+_val,dst+1,now);
}

void dfs2(int now,int val,int dst,int p) {
    if(K<val) return;
    X[val]=min(X[val],dst);
    for(auto [nxt,_val]:E[now]) if(nxt!=p&&!chk[nxt]) dfs2(nxt,val+_val,dst+1,now);
}

void dfs3(int now,int val,int p) {
    if(K<val) return;
    X[val]=1e9;
    for(auto [nxt,_val]:E[now]) if(nxt!=p&&!chk[nxt]) dfs3(nxt,val+_val,now);
}

void dec(int now,int p) {
    chk[now]=1; X[0]=0;
    for(auto [nxt,val]:E[now]) if(nxt!=p&&!chk[nxt]) dfs1(nxt,val,1,now),dfs2(nxt,val,1,now);
    for(auto [nxt,val]:E[now]) if(nxt!=p&&!chk[nxt]) dfs3(nxt,val,now);
    for(auto [nxt,val]:E[now]) if(nxt!=p&&!chk[nxt]) dec(cen(nxt,sz(nxt,now),now),now);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;
    for(int i=1;i<N;i++) {
        int u,v,x; cin>>u>>v>>x;
        E[u].emplace_back(v,x);
        E[v].emplace_back(u,x);
    }

    for(int i=0;i<MXK;i++) X[i]=1e9; 
    dec(cen(0,sz(0,-1),-1),-1);
    cout<<(ans==1e9?-1:ans);
}