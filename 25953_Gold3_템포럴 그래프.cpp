#include <bits/stdc++.h>

using namespace std;

int n,t,m,s,e,DP[1001][10000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>t>>m>>s>>e;

    for (int T=0;T<=t;T++) for (int i=0;i<n;i++) DP[T][i]=1e9;
    DP[0][s]=0;
    for (int T=0;T<t;T++) {
        for (int i=0;i<m;i++) {
            int u,v,w;cin>>u>>v>>w;
            DP[T+1][v]=min(DP[T+1][v],DP[T][u]+w);
            DP[T+1][u]=min(DP[T+1][u],DP[T][v]+w);
        }
        for (int i=0;i<n;i++) DP[T+1][i]=min(DP[T+1][i],DP[T][i]);
    }
    cout << (DP[t][e]==1e9?-1:DP[t][e]);
}