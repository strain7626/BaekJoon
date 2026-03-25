#include <bits/stdc++.h>

using namespace std;

int N,K,M,vis[100000],pre[100000],cur;
vector<pair<int,int>> A;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;
    for(int i=1,x;i<=N;i++) cin>>x,A.push_back({x,i});

    sort(A.begin(),A.end());
    auto [a,b]=A[N-1];A.pop_back();
    
    for(auto [l,i]:A) for(int k=K-1;k>=l;k--) if(!vis[k]&&(k==l||vis[k-l])) vis[k]=i,pre[k]=k-l,M=max(M,k);

    vis[0]=b;
    vector<int> ans={vis[cur=M]};

    while(cur) ans.push_back(vis[cur=pre[cur]]);

    cout<<ans.size()<<' '<<M+a<<'\n';
    for(int i:ans) cout<<i<<' ';
}