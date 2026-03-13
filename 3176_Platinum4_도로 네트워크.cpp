#include <bits/stdc++.h>
#define MXN 100001

using namespace std;
using ll=long long;

int N,K,dep[MXN],anc[MXN][20],stm[MXN][20],stM[MXN][20];
vector<pair<int,int>> adj[MXN];

void DFS(int now) {
    for(auto &[nxt,val]:adj[now]) if(nxt!=anc[now][0]) {
        anc[nxt][0]=now;
        dep[nxt]=dep[now]+1;
        stm[nxt][0]=stM[nxt][0]=val;
        DFS(nxt);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int k=0;k<20;k++) stm[0][k]=1e9,stM[0][k]=-1e9;
    
    cin>>N;
    for(int i=1;i<N;i++) {
        int A,B,C;cin>>A>>B>>C;
        adj[A].push_back({B,C});
        adj[B].push_back({A,C});
    }

    DFS(1);
    for(int k=1;k<20;k++) for(int i=1;i<=N;i++) {
        anc[i][k]=anc[anc[i][k-1]][k-1];
        stm[i][k]=min(stm[i][k-1],stm[anc[i][k-1]][k-1]);
        stM[i][k]=max(stM[i][k-1],stM[anc[i][k-1]][k-1]);
    }

    cin>>K;
    while(K--) {
        int S,E;cin>>S>>E;
        if(dep[S]>dep[E]) swap(S,E);
        
        int D=dep[E]-dep[S],m=1e9,M=-1e9;
        for(int k=0;k<20;k++) {
            if(D&1) {
                m=min(m,stm[E][k]);
                M=max(M,stM[E][k]);
                E=anc[E][k];
            }
            D>>=1;
        }
        
        if(S==E) {
            cout<<m<<' '<<M<<'\n';
            continue;
        }
        
        for(int k=19;k>=0;k--) {
            if(anc[S][k]==anc[E][k]) continue;
            m=min(m,min(stm[S][k],stm[E][k]));
            M=max(M,max(stM[S][k],stM[E][k]));
            S=anc[S][k];
            E=anc[E][k];
        }

        cout<<min(m,min(stm[S][0],stm[E][0]))<<' '<<max(M,max(stM[S][0],stM[E][0]))<<'\n';
    }
}