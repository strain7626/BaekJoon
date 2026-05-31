#include <bits/stdc++.h>

using namespace std;

const int MXN=100001;
int N,M,bit[MXN],in[MXN],out[MXN],cnt;
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

    int x;
    cin>>N>>M>>x;
    for(int i=2;i<=N;i++) cin>>x,E[x].push_back(i);
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