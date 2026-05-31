#include <bits/stdc++.h>

using namespace std;

int N,D,A[1001][1001],B[1001][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>D;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin>>B[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) A[i][j]=B[i][j]+A[i-1][j]+A[i][j-1]-A[i-1][j-1];

    int ans=2e9,a,b;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(!B[i][j]) {
        int l=max(1,j-D),r=min(N,j+D),u=max(1,i-D),d=min(N,i+D);
        int sum=A[d][r]-A[d][l-1]-A[u-1][r]+A[u-1][l-1];
        if(sum<ans) a=i,b=j,ans=sum;
    }
    cout<<a<<' '<<b<<'\n';
    if(ans) cout<<ans;
}