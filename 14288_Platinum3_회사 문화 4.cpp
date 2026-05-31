#include <bits/stdc++.h>

using namespace std;

const int MXN=100001;

int N,M,cnt,bit[MXN][2],in[MXN],out[MXN];
vector<int> E[MXN];
bool rev;

void update(int i,int d) {while(i<=N) bit[i][rev]+=d,i+=(i&-i);}

int query(int i,bool r) {
    int res=0;
    while(i) res+=bit[i][r],i-=(i&-i);
    return res;
}

void dfs(int n) {
    in[n]=++cnt;
    for(int i:E[n]) dfs(i);
    out[n]=cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int x,i=1;i<=N;i++) cin>>x,i>1?E[x].push_back(i):(void)0;

    dfs(1);

    while(M--) {
        int Q,i,w;cin>>Q;
        if(Q==3) {rev=!rev;continue;}
        
        cin>>i;
        if(Q==1) {
            cin>>w;
            update(in[i],w);
            if(!rev) update(out[i]+1,-w);
        } else cout<<query(in[i],0)+query(out[i],1)-query(in[i]-1,1)<<'\n';
    }
}