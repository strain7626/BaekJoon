#include <bits/stdc++.h>

using namespace std;

const int MOD=1000007;

int w,h,x,y,DP[201][201];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>w>>h>>x>>y;
    DP[1][0]=1;
    for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) DP[i][j]=(DP[i-1][j]+DP[i][j-1])%MOD;
    for(int i=x;i<=w;i++) for(int j=y;j<=h;j++) DP[i][j]=(DP[i-1][j]+DP[i][j-1])%MOD;
    cout<<DP[w][h];
}