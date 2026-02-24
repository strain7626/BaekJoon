#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,M,ans;
vector<pair<ll,ll>> adj[300001];

ll BFS(int i) {
    queue<ll> Q;Q.push(1);
    vector<bool> vis(N+1);vis[1]=1;

    while(!Q.empty()) {
        int u=Q.front();Q.pop();
        if(u==N) return 0;
        for(auto [v,w]:adj[u]) {
            if(vis[v]) continue;
            if((1LL<<i)&w) continue;
            if((~ans>>i)&(w>>i)) continue;

            vis[v]=1;
            Q.push(v);
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        ll u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=59;i>=0;i--) ans|=BFS(i)<<i;

    cout<<ans<<'\n';
}