#include <bits/stdc++.h>
#define MXN 100001

using namespace std;

int N,M,cnt,vis[MXN],low[MXN],scc[MXN],inD[MXN];
bool inS[MXN];
vector<int> adj[MXN];
stack<int> S;

void DFS(int now) {
    low[now]=vis[now]=++cnt;
    S.push(now);
    inS[now]=1;

    for(int nxt:adj[now]) {
        if(!vis[nxt]) {
            DFS(nxt);
            low[now]=min(low[now],low[nxt]);
        } else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
    }
    
    if(vis[now]!=low[now]) return;

    while(!S.empty()) {
        int s=S.top();S.pop();
        scc[s]=now;
        inS[s]=0;
        if(s==now) break;
    }
}

void solve() {
    cin>>N>>M;

    cnt=0;
    for(int i=1;i<=N;i++) {
        vis[i]=low[i]=scc[i]=inD[i]=inS[i]=0;
        adj[i].clear();
    }

    while(M--) {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i=1;i<=N;i++) if(!vis[i]) DFS(i);
    
    for(int i=1;i<=N;i++) for(int j:adj[i]) if(scc[i]!=scc[j]) inD[scc[j]]++;

    int ans=0;
    for(int i=1;i<=N;i++) ans+=(i==scc[i]&&!inD[i]);

    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;
    while(T--) {
        solve();
    }
}