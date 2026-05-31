#include <bits/stdc++.h>

using namespace std;

const int MXN=1e5+5;

int N,A[MXN],vis[MXN],ans;

void DFS(int now) {
    vis[now]=-1;
    int nxt=A[now];
    if(vis[nxt]==-1) vis[now]=nxt;
    else if(!vis[nxt]) {DFS(nxt);vis[now]=(vis[nxt]==nxt?N+1:vis[nxt]);}
    else vis[now]=N+1;
}

void solve() {
    cin>>N;
    ans=0;
    for(int i=1;i<=N;i++) cin>>A[i],vis[i]=0;
    for(int i=1;i<=N;i++) if(!vis[i]) DFS(i);
    for(int i=1;i<=N;i++) if(vis[i]==N+1) ans++;
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) solve();
}