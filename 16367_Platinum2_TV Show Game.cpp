#include <bits/stdc++.h>
#define MXN 10001
#define P 5000

using namespace std;

int k,n,cnt,snt,vis[MXN],low[MXN],scc[MXN];
vector<int> adj[MXN];
stack<int> S;
bool inS[MXN];

void DFS(int now) {
    vis[now]=low[now]=++cnt;
    S.push(now);
    inS[now]=1;

    for(int nxt:adj[now]) {
        if(!vis[nxt]) DFS(nxt),low[now]=min(low[now],low[nxt]);
        else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
    }

    if(vis[now]!=low[now]) return;

    ++snt;
    while(1) {
        int s=S.top();S.pop();
        scc[s]=snt;
        inS[s]=0;
        if(s==now) return;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>k>>n;
    while(n--) {
        int a,b,c;char l;
        cin>>a>>l; if(l=='R') a=-a;
        cin>>b>>l; if(l=='R') b=-b;
        cin>>c>>l; if(l=='R') c=-c;

        adj[P-a].push_back(P+b);
        adj[P-a].push_back(P+c);
        adj[P-b].push_back(P+a);
        adj[P-b].push_back(P+c);
        adj[P-c].push_back(P+a);
        adj[P-c].push_back(P+b);
    }

    for(int i=1;i<=k;i++) {
        if(!vis[P-i]) DFS(P-i);
        if(!vis[P+i]) DFS(P+i);
    }
    for(int i=1;i<=k;i++) if(scc[P-i]==scc[P+i]) {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=k;i++) cout<<(scc[P-i]<scc[P+i]?'R':'B');
}