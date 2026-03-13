#include <bits/stdc++.h>
#define MXN 500001

using namespace std;

int N,M,S,P,atm[MXN],sum[MXN];
bool res[MXN];
vector<int> adj[MXN];

int cnt,vis[MXN],low[MXN];
bool inS[MXN];
stack<int> stk;

int scc[MXN],inD[MXN];
vector<int> dag[MXN];

void DFS(int now) {
    vis[now]=low[now]=++cnt;
    stk.push(now);
    inS[now]=1;

    for(int nxt:adj[now]) {
        if(!vis[nxt]) DFS(nxt),low[now]=min(low[now],low[nxt]);
        else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
    }

    if(vis[now]!=low[now]) return;
    
    while(!stk.empty()) {
        int s=stk.top();stk.pop();
        scc[s]=now;
        inS[s]=0;
        if(s==now) break;
        atm[now]+=atm[s];
        res[now]|=res[s];
    }
}

void DAG(int now) {for(int nxt:dag[now]) if(!inD[nxt]++) DAG(nxt);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=N;i++) cin>>atm[i];

    cin>>S>>P;
    for(int i=0;i<P;i++) {
        int t;cin>>t;
        res[t]=1;
    }

    for(int i=1;i<=N;i++) if(!vis[i]) DFS(i);

    for(int i=1;i<=N;i++) for(int j:adj[i]) if(scc[j]!=scc[i]) dag[scc[i]].push_back(scc[j]);

    for(int i=1;i<=N;i++) if(i==scc[i]) {
        sort(dag[i].begin(),dag[i].end());
        dag[i].erase(unique(dag[i].begin(),dag[i].end()),dag[i].end());
    }

    S=scc[S];
    DAG(S);
    
    queue<int> Q;
    Q.push(S);
    
    int ans=0;
    sum[S]=atm[S];
    
    while(!Q.empty()) {
        int now=Q.front();Q.pop();
        if(res[now]) ans=max(ans,sum[now]);

        for(int nxt:dag[now]) {
            sum[nxt]=max(sum[nxt],sum[now]+atm[nxt]);
            if(!--inD[nxt]) Q.push(nxt);
        }
    }

    cout<<ans;
}