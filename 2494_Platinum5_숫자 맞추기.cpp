#include <bits/stdc++.h>

using namespace std;

int N,DP[10001][10],pre[10001][10],ans[10001];
string A,B;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<=N;i++) for(int j=0;j<10;j++) DP[i][j]=1e9;
    cin>>A>>B;
    DP[0][0]=0;pre[0][0]=10;
    for(int i=0;i<N;i++) for(int j=0;j<10;j++) {
        int l=(B[i]-A[i]-j+20)%10,r=(A[i]-B[i]+j+10)%10;
        if(DP[i+1][(B[i]-A[i]+10)%10]>DP[i][j]+l) DP[i+1][(B[i]-A[i]+10)%10]=DP[i][j]+l,pre[i+1][(B[i]-A[i]+10)%10]=l;
        if(DP[i+1][j]>DP[i][j]+r) DP[i+1][j]=DP[i][j]+r,pre[i+1][j]=-r;
    }
    int m=0;
    for(int i=1;i<10;i++) if(DP[N][m]>DP[N][i]) m=i;
    cout<<DP[N][m]<<'\n';
    for(int i=N;i>0;i--) ans[i]=pre[i][m],m=(pre[i][m]<0?m:(m-pre[i][m]+10)%10);
    for(int i=1;i<=N;i++) cout<<i<<' '<<ans[i]<<'\n';
}