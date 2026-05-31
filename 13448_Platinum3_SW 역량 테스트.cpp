#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=100000;

ll N,T,M[50],P[50],R[50],idx[50],DP[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>T;
    for(int i=0;i<N;i++) idx[i]=i;
    for(int i=0;i<N;i++) cin>>M[i];
    for(int i=0;i<N;i++) cin>>P[i];
    for(int i=0;i<N;i++) cin>>R[i];

    sort(idx,idx+N,[](int i,int j){return P[i]*R[j]>P[j]*R[i];});

    for(int i=0;i<N;i++) for(int t=T;t>=R[idx[i]];t--) DP[t]=max(DP[t],DP[t-R[idx[i]]]+M[idx[i]]-t*P[idx[i]]);
    cout<<*max_element(DP,DP+T+1);
}