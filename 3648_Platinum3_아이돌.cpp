#include <bits/stdc++.h>
#define MXN 2001
#define P 1000

using namespace std;

int n,m,cnt,vis[MXN],low[MXN],scc[MXN];
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
    
    while(1) {
        int s=S.top();S.pop();
        scc[s]=now;
        inS[s]=0;
        if(s==now) break;
    }    
}    

string solve() {
    
    for(int i=1;i<=n;i++) adj[P-i]=adj[P+i]={},vis[P-i]=vis[P+i]=0;
    
    adj[P-1].push_back(P+1);
    while(m--) {
        int a,b;cin>>a>>b;
        adj[P-a].push_back(P+b);
        adj[P-b].push_back(P+a);
    }
    
    for(int i=1;i<=n;i++) {
        if(!vis[P-i]) DFS(P-i);
        if(!vis[P+i]) DFS(P+i);
    }
    
    for(int i=1;i<=n;i++) if(scc[P-i]==scc[P+i]) return "no\n";
    return "yes\n";
}        


int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while(cin>>n>>m) cout<<solve();
}