#include <bits/stdc++.h>

using namespace std;

int N,DP[10001][10],pre[10001][10];
string A,B;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<=N;i++) for(int j=0;j<10;j++) DP[i][j]=1e9;
    cin>>A>>B;
    DP[0][0]=0;
    for(int i=0;i<N;i++) for(int j=0;j<10;j++) {
        DP[i+1][j]=min(DP[i+1][j],DP[i][j]+(A[i]-B[i]+j+10)%10);
        DP[i+1][(B[i]-A[i]+10)%10]=min(DP[i+1][(B[i]-A[i]+10)%10],DP[i][j]+(B[i]-A[i]-j+20)%10);
    }
    cout<<*min_element(DP[N],DP[N]+10);
}