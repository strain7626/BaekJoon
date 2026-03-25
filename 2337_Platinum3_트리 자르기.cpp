#include <bits/stdc++.h>

using namespace std;

int N,M,DP[151][151],siz[151];
vector<int> adj[151];

void DFS(int now,int pre) {
    DP[now][1]=0;
    siz[now]=1;

    for(int nxt:adj[now]) if(nxt!=pre) {
        DFS(nxt,now);
        for(int i=min(M,siz[now]+=siz[nxt]);i>0;i--) {DP[now][i]++;for(int k=1;k<=min(i-1,siz[nxt]);k++) DP[now][i]=min(DP[now][i],DP[now][i-k]+DP[nxt][k]);}
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0;i<=150;i++) for(int j=0;j<=150;j++) DP[i][j]=1e9;

    cin>>N>>M;
    for(int i=1,A,B;i<N;i++) {
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    DFS(1,0);

    int m=DP[1][M];
    for(int i=2;i<=N;i++) m=min(m,DP[i][M]+1);
    cout<<m;
}