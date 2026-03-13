#include <bits/stdc++.h>
#define MXN 100001

using namespace std;

int N,M,cnt,vis[MXN],low[MXN],scc[MXN];
bool inS[MXN],inD[MXN];
vector<int> adj[MXN];
stack<int> S;

void DFS(int now) {
    vis[now]=low[now]=++cnt;
    inS[now]=1;
    S.push(now);

    for(int nxt:adj[now]) {
        if(!vis[nxt]) DFS(nxt),low[now]=min(low[now],low[nxt]);
        else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
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
    while(!S.empty()) S.pop();
    for(int i=0;i<N;i++) {
        vis[i]=low[i]=scc[i]=inS[i]=inD[i]=0;
        adj[i].clear();
    }

    while(M--) {
        int A,B;cin>>A>>B;
        adj[A].push_back(B);
    }

    for(int i=0;i<N;i++) if(!vis[i]) DFS(i);

    for(int i=0;i<N;i++) for(int j:adj[i]) if(scc[i]!=scc[j]) inD[scc[j]]=1;

    int ans=-1;
    for(int i=0;i<N;i++) {
        if(i==scc[i]&&!inD[i]) {
            if(ans==-1) ans=i;
            else {
                cout<<"Confused\n\n";
                return;
            }
        }
    }
    
    for(int i=0;i<N;i++) if(scc[i]==ans) cout<<i<<'\n';
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;cin>>T;
    while(T--) solve();
}