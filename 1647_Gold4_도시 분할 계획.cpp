#include <bits/stdc++.h>

using namespace std;

int N,M,uni[100001],siz[100001];
int find(int n) {return (uni[n]==n?n:uni[n]=find(uni[n]));}
tuple<int,int,int> adj[1000000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=0;i<N;i++) uni[i]=i,siz[i]=1;
    for(int i=0;i<M;i++) {
        int A,B,C;cin>>A>>B>>C;
        adj[i]={C,A,B};
    }

    int ans=0;
    sort(adj,adj+M);
    for(int i=0;i<M;i++) {
        auto [C,A,B]=adj[i];
        if(siz[find(A)]+siz[find(B)]==N||find(A)==find(B)) continue;
        siz[find(B)]+=siz[find(A)];
        uni[find(A)]=uni[find(B)];
        ans+=C;
    }
    cout<<ans;
}