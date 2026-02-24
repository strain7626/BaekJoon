#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,W[200001],w,D[200001];
vector<int> E[200001];

ll DFS1(int n,int p) {
    for(int i:E[n]) if(i!=p) D[n]+=DFS1(i,n);
    return D[n]+=W[n];
}
ll DFS2(int n,int p) {
    ll res=0;
    for(int i:E[n]) if(i!=p) res+=DFS2(i,n)+D[i];
    return res;
}
ll DFS3(int n,int p,ll d) {
    ll res=d;
    for(int i:E[n]) if(i!=p) res=max(res,DFS3(i,n,d+w-2*D[i]));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<N;i++) {
        int a,b;cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for(int i=1;i<=N;i++) cin>>W[i],w+=W[i];

    DFS1(1,0);
    cout<<DFS3(1,0,DFS2(1,0));
}