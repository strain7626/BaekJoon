#include <bits/stdc++.h>
#define MXN 100000

using namespace std;

int N,uni[MXN];
int find(int n) {return uni[n]==n?n:uni[n]=find(uni[n]);}
pair<int,int> X[MXN],Y[MXN],Z[MXN];
pair<int,pair<int,int>> adj[3*MXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        int x,y,z;cin>>x>>y>>z;
        X[i]={x,i};
        Y[i]={y,i};
        Z[i]={z,i};
        uni[i]=i;
    }
    sort(X,X+N);
    sort(Y,Y+N);
    sort(Z,Z+N);

    for(int i=0;i<N-1;i++) {
        adj[i*3]={X[i+1].first-X[i].first,{X[i].second,X[i+1].second}};
        adj[i*3+1]={Y[i+1].first-Y[i].first,{Y[i].second,Y[i+1].second}};
        adj[i*3+2]={Z[i+1].first-Z[i].first,{Z[i].second,Z[i+1].second}};
    }
    sort(adj,adj+(N-1)*3);

    int ans=0;
    for(int i=0;i<3*(N-1);i++) {
        if(find(adj[i].second.first)==find(adj[i].second.second)) continue;
        uni[find(adj[i].second.first)]=find(adj[i].second.second);
        ans+=adj[i].first;
    }
    cout<<ans;
}