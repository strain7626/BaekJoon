#include <bits/stdc++.h>
#define MXV 10001

using namespace std;

int V,E,cnt,low[MXV],vis[MXV];
bool inS[MXV];
vector<int> adj[MXV];
stack<int> S;
vector<vector<int>> SCC;

void DFS(int now) {
    vis[now]=low[now]=++cnt;
    S.push(now);
    inS[now]=1;

    for(int &nxt:adj[now]) {
        if(!vis[nxt]) {
            DFS(nxt);
            low[now]=min(low[now],low[nxt]);
        } else if(inS[nxt]) low[now]=min(low[now],vis[nxt]);
    }

    if(low[now]==vis[now]) {
        SCC.push_back({});

        while(!S.empty()) {
            int s=S.top();S.pop();
            inS[s]=0;
            SCC.back().push_back(s);
            if(s==now) break;
        }

        sort(SCC.back().begin(),SCC.back().end());
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>V>>E;
    for(int i=0;i<E;i++) {
        int A,B;cin>>A>>B;
        adj[A].push_back(B);
    }

    for(int i=1;i<=V;i++) if(!vis[i]) DFS(i);
    
    sort(SCC.begin(),SCC.end());

    cout<<SCC.size()<<'\n';
    for(auto &scc:SCC) {
        for(int &i:scc) cout<<i<<' ';
        cout<<-1<<'\n';
    }
}