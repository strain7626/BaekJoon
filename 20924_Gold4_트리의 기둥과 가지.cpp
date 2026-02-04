#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

int N,R,G,ans1,ans2;
bool vis[MAX+1];
vector<pair<int,int>> adj[MAX+1];

int DFS(int now, int sum) {
    int res=sum;
    vis[now]=1;
    for (auto [nxt,d]:adj[now]) if (!vis[nxt]) {
        res = max(res,DFS(nxt,sum+d));
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>R;
    for (int i=1;i<N;i++) {
        int a,b,d;cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }

    vis[R]=1;
    if (adj[R].size()==1) {
        tie(G,ans1)=adj[R][0];
        vis[G]=1;
        while (adj[G].size()==2) for (auto [n,d]:adj[G]) if (!vis[n]) {
            vis[G=n]=1,ans1+=d;
            break;
        }
    }
    else G=R,ans1=0;

    ans2=DFS(G,0);

    cout << ans1 << ' ' << ans2;
}