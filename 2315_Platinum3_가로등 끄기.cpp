#include <bits/stdc++.h>

using namespace std;

int N,M,DP[1001][1001][2],D[1001],S[1001];

int go(int l,int r,int t) {
    if(DP[l][r][t]||(l==1&&r==N)) return DP[l][r][t];
    return DP[l][r][t]=min(l>1?go(l-1,r,0)+(S[N]-S[r]+S[l-1])*(D[t?r:l]-D[l-1]):1e9,r<N?go(l,r+1,1)+(S[N]-S[r]+S[l-1])*(D[r+1]-D[t?r:l]):1e9);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M;
    for(int i=1,x,y;i<=N;i++) cin>>D[i]>>S[i],S[i]+=S[i-1];
    cout<<go(M,M,0);
}