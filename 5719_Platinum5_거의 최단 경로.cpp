#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int N,M,S,E,vis[500],val[500][500];
vector<int> rev[500];
vector<int> adj[500];

void Dijkstra() {
    for(int i=0;i<N;i++) vis[i]=1e9;
    priority_queue<pii,vector<pii>,greater<>> PQ;
    PQ.push({0,S});
    vis[S]=0;

    while(!PQ.empty()) {
        auto [dst,now]=PQ.top();PQ.pop();
        if(now==E) continue;

        for(int nxt:adj[now]) {
            int cst=dst+val[now][nxt];
            if(cst>vis[nxt]) continue;
            if(cst==vis[nxt]) {
                rev[nxt].push_back(now);
                continue;
            }
            rev[nxt]={now};
            PQ.push({vis[nxt]=cst,nxt});
        }
    }
}

void DFS(int now) {
    for(int pre:rev[now]) {
        if(val[pre][now]==1e9) continue;
        val[pre][now]=1e9;
        DFS(pre);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    while(1) {
        cin>>N>>M;
        if(!N&&!M) break;

        for(int i=0;i<N;i++) {
            rev[i].clear();
            adj[i].clear();
        }

        cin>>S>>E;
        for(int i=0;i<M;i++) {
            int U,V,P;cin>>U>>V>>P;
            adj[U].push_back(V);
            val[U][V]=P;
        }
        
        Dijkstra();
        DFS(E);
        Dijkstra();
        cout<<(vis[E]==1e9?-1:vis[E])<<'\n';
    }
}