#include <bits/stdc++.h>

using namespace std;

int N,M,adj[501][501];

void Floyd() {
    for (int k=1;k<=N;k++) for (int i=1;i<=N;i++) for (int j=1;j<=N;j++)
        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) cin >> adj[i][j];

    Floyd();

    while (M--) {
        int A,B,C;cin>>A>>B>>C;
        cout<<(adj[A][B]<=C?"Enjoy other party":"Stay here")<<'\n';
    }
}