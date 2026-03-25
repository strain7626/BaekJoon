#include <bits/stdc++.h>
#define MXN 20001
#define P 10000

using namespace std;

int N,M,cnt,snt,vis[MXN],low[MXN],scc[MXN];
vector<int> adj[MXN];
bool inS[MXN];
stack<int> S;

void DFS(int now) {
    vis[now]=low[now]=++cnt;
    S.push(now);
    inS[now]=1;

    for(int nxt:adj[now]) {
        if(!vis[nxt]) DFS(nxt),low[now]=min(low[now],low[nxt]);
        else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
    }

    if(vis[now]!=low[now]) return;

    snt++;
    while(!S.empty()) {
        int s=S.top();S.pop();
        scc[s]=snt;
        inS[s]=0;
        if(s==now) break;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    while(M--) {
        int i,j;cin>>i>>j;
        adj[P-i].push_back(P+j);    
        adj[P-j].push_back(P+i);    
    }

    for(int i=1;i<=N;i++) {
        if(!vis[P-i]) DFS(P-i);
        if(!vis[P+i]) DFS(P+i);
    }
    
    for(int i=1;i<=N;i++) if(scc[P-i]==scc[P+i]) {
        cout<<0;
        return 0;
    }

    cout<<1<<'\n';
    for(int i=1;i<=N;i++) cout<<(scc[P-i]>scc[P+i])<<' ';
}