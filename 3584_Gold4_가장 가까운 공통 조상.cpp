#include <bits/stdc++.h>

using namespace std;

int T,N,A,B,par[10001],vis[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>T;while(T--) {
        cin>>N;
        for(int i=1;i<=N;i++) par[i]=vis[i]=0;
        for(int i=1;i<N;i++) cin>>A>>B,par[B]=A;
        cin>>A>>B;
        
        int n;
        for(n=A;n;n=par[n]) vis[n]=1;
        for(n=B;!vis[n];n=par[n]);
        cout<<n<<'\n';
    }
}