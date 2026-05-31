#include <bits/stdc++.h>

using namespace std;

const int MXN=100001;

int N,M,P[MXN],cnt,bit[MXN],in[MXN],out[MXN];
vector<int> E[MXN];

void update(int i,int d) {while(i<=N) bit[i]+=d,i+=(i&-i);}

int query(int i) {
    int res=0;
    while(i) res+=bit[i],i-=(i&-i);
    return res;
}

void dfs(int n) {
    in[n]=++cnt;
    for(int i:E[n]) dfs(i);
    out[n]=cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M>>P[1];
    for(int i=2;i<=N;i++) cin>>P[i],E[P[i]].push_back(i);

    dfs(1);

    while(M--) {
        int Q,i,w;cin>>Q>>i;
        if(Q==1) {
            cin>>w;
            update(in[i],w);
        } else cout<<query(out[i])-query(in[i]-1)<<'\n';
    }
}