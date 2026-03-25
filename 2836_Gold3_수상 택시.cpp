#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<pair<int,int>> A={{2e9,2e9}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    while(N--) {
        int u,v;cin>>u>>v;
        if(u>v) A.push_back({v,u});
    }
    sort(A.begin(),A.end());

    int l=0,r=0;
    long long ans=0;
    for(auto [v,u]:A) {
        if(r<v) ans+=(r-l)*2,l=v,r=u;
        r=max(r,u);
    }

    cout<<ans+M;
}