#include <bits/stdc++.h>
#define MXN 100001

using namespace std;
using ll=long long;

int N,anc[MXN][20],dep[MXN];
ll pre[MXN][20];
vector<pair<int,ll>> adj[MXN];

void DFS(int now) {
    for(auto &[nxt,w]:adj[now]) {
        if(nxt==anc[now][0])continue;
        pre[nxt][0]=w;
        anc[nxt][0]=now;
        dep[nxt]=dep[now]+1;
        DFS(nxt);
    }
}

ll Q1(int u,int v) {
    ll res=0;
    
    if(dep[u]>dep[v]) swap(u,v);

    int D=dep[v]-dep[u];
    for(int k=0;k<20;k++) {
        if(D&1) {
            res+=pre[v][k];
            v=anc[v][k];
        }
        D>>=1;
    }
    if(u==v) return res;
    for(int k=19;k>=0;k--) {
        if(anc[u][k]==anc[v][k]) continue;
        res+=pre[u][k]+pre[v][k];
        u=anc[u][k];
        v=anc[v][k];
    }

    return res+pre[u][0]+pre[v][0];
}

int LCA(int u,int v) {
    if(dep[u]>dep[v]) swap(u,v);

    int D=dep[v]-dep[u];
    for(int k=0;k<20;k++) {
        if(D&1) v=anc[v][k];
        D>>=1;
    }

    if(u==v) return u;

    for(int k=19;k>=0;k--) {
        if(anc[u][k]==anc[v][k]) continue;
        u=anc[u][k];
        v=anc[v][k];
    }

    return anc[u][0];
}

int Q2(int u,int v,int K) {
    if(K==1) return u;

    int lca=LCA(u,v);
    if(K==dep[u]+dep[v]-2*dep[lca]+1) return v;

    if(K<=dep[u]-dep[lca]+1) {
        K--;
        for(int k=0;k<20;k++) {
            if(K&1) u=anc[u][k];
            K>>=1;
        }
        return u;
    }

    K=dep[u]+dep[v]-2*dep[lca]+1-K;

    for(int k=0;k<20;k++) {
        if(K&1) v=anc[v][k];
        K>>=1;
    }
    return v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin>>N;
    for(int i=1;i<N;i++) {
        int u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    DFS(1);
    for(int k=1;k<20;k++) for(int i=1;i<=N;i++) {
        anc[i][k]=anc[anc[i][k-1]][k-1];
        pre[i][k]=pre[i][k-1]+pre[anc[i][k-1]][k-1];
    }

    int M;cin>>M;
    while(M--) {
        int Q,u,v,k;cin>>Q>>u>>v;
        if(Q==1) cout<<Q1(u,v)<<'\n';
        else cin>>k,cout<<Q2(u,v,k)<<'\n';
    }
}