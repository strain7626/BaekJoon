#include <bits/stdc++.h>

using namespace std;

const int P=1000;

int N,M,P1,P2,vis[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    if(N) cin>>P1;
    if(N>1) cin>>P2;
    
    M+=P;

    queue<int> Q;
    Q.push(P);
    vis[P]=1;

    while(!Q.empty()) {
        int n=Q.front();Q.pop();
        
        if(n==M) {cout<<vis[n]-1;return 0;}
        
        if(0<=n+P1&&n+P1<=2000&&!vis[n+P1]) vis[n+P1]=vis[n]+1,Q.push(n+P1);
        if(0<=n+P2&&n+P2<=2000&&!vis[n+P2]) vis[n+P2]=vis[n]+1,Q.push(n+P2);
    }
    cout<<-1;
}