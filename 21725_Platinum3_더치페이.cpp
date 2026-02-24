#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int N,M,uni[100001];
ll w[100001],d[100001];
set<int> S[100001];

int find(int n) {return (uni[n]==n?n:uni[n]=find(uni[n]));}
void merge(int x,int y) {
    x=find(x);y=find(y);
    if(S[x].size()>S[y].size()) swap(x,y);
    uni[x]=y;
    for(int i:S[x]) d[i]+=w[x]-w[y],S[y].insert(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1;i<=N;i++) S[i].insert(i),uni[i]=i;
    
    while(M--) {
        ll c,x,y;cin>>c>>x>>y;
        if(c==1) merge(x,y);
        else d[x]-=y,w[find(x)]+=y/S[find(x)].size();
    }

    vector<tuple<int,int,ll>> ans;
    for(int x=find(1),y=1;y<=N;y++) {
        if(x==y)continue;
        ll c=w[x]+d[y];
        if(c<0) ans.push_back({x,y,-c});
        if(c>0) ans.push_back({y,x,c});
    }

    cout<<ans.size()<<'\n';
    for(auto [x,y,c]:ans) cout<<x<<' '<<y<<' '<<c<<'\n';
}