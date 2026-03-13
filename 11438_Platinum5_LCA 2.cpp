#include <bits/stdc++.h>

using namespace std;

int N,M,anc[100001][20],dep[100001];
vector<int> adj[100001];

void DFS(int now) {
    for(int &i:adj[now]) if(i!=anc[now][0]) {
        anc[i][0]=now;
        dep[i]=dep[now]+1;
        DFS(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<N;i++) {
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

    for(int k=1;k<20;k++) for(int i=1;i<=N;i++) anc[i][k]=anc[anc[i][k-1]][k-1];
    
    cin>>M;
    while(M--) {
        int A,B;cin>>A>>B;
        if(dep[A]>dep[B]) swap(A,B);
        int D=dep[B]-dep[A];
        for(int k=0;k<20;k++) {
            if(D&1) B=anc[B][k];
            D>>=1;
        }
        if(A==B) {
            cout<<A<<'\n';
            continue;
        }
        for(int k=19;k>=0;k--) if(anc[A][k]!=anc[B][k]) A=anc[A][k],B=anc[B][k];
        cout<<anc[A][0]<<'\n';
    }
    
}