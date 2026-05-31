#include <bits/stdc++.h>

using namespace std;

const int MXN=1e5+1;

int N,M,P[MXN],in[MXN],out[MXN],bit[MXN],cnt;
vector<int> E[MXN];

void dfs(int n) {
    in[n]=++cnt;
    for(int i:E[n]) dfs(i);
    out[n]=cnt;
}

void update(int i,int d) {while(i<=N) bit[i]+=d,i+=(i&-i);}
int query(int i) {
    int res=0;
    while(i) res+=bit[i],i-=(i&-i);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int x,i=1;i<=N;i++) {cin>>x;if(i>1) E[x].push_back(i);}
    dfs(1);

    while(M--) {
        int Q,i,w;cin>>Q>>i;
        if(Q==1) {
            cin>>w;
            update(in[i],w);
            update(out[i]+1,-w);
        } else cout<<query(in[i])<<'\n';
    }
}