#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,M,L[2501],C[2501],r[2000001],dp[101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>M;
    for(int i=1;i<=M;i++) cin>>L[i];
    for(int i=1;i<=M;i++) cin>>C[i];
    for(int i=1;i<=N;i++) cin>>r[i];

    for(int r1=1;r1<=100;r1++) for(int r2=1;r2<=100;r2++) {
        ll lim=0,cur=0;
        for(int i=1;i<=M;i++) {
            int d=(lim+=L[i]*r1)+C[i]-cur-dp[r1][r2];
            cur+=L[i]*r2;

            if(d>0) dp[r1][r2]+=d;
        }
        dp[r1][r2]-=lim;
    }

    ll l=accumulate(L,L+M+1,0LL),T=0;
    for(int i=1;i<=N;i++) cout<<(T+=dp[r[i-1]][r[i]]+l*r[i])<<' ';
}