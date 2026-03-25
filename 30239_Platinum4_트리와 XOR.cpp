#include <bits/stdc++.h>
#define MXN 200001

using namespace std;
using ll=long long;

int N,A[MXN],S[MXN];
ll ans[MXN];
vector<pair<int,ll>> E[MXN];

void DFS1(int n,int p) {
    for(auto [i,c]:E[n]) if(i!=p) DFS1(i,n),ans[1]+=S[i]*c,S[n]+=S[i];
}
void DFS2(int n,int p) {
    for(auto [i,c]:E[n]) if(i!=p) ans[i]=ans[n]+c*(N-2*S[i]),DFS2(i,n);
}

void solve() {
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i],S[i]=1,E[i].clear();
    for(int i=1,u,v;i<N;i++) {
        cin>>u>>v;
        E[u].push_back({v,A[u]^A[v]});
        E[v].push_back({u,A[u]^A[v]});
    }

    ans[1]=0;
    DFS1(1,0);
    DFS2(1,0);
    for(int i=1;i<=N;i++) cout<<ans[i]<<' ';cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;cin>>T;while(T--) solve();
}