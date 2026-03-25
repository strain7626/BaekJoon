#include <bits/stdc++.h>

using namespace std;

string A;
int N,DP[2501];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>A;
    N=A.size();
    A='0'+A;

    for(int i=1;i<=2500;i++) DP[i]=1e9;

    for(int i=1,j;i<=N;i++) {
        for(j=0;1<=i-j&&i+j<=N;j++) if(A[i-j]==A[i+j]) DP[i+j]=min(DP[i+j],DP[i-j-1]+1); else break;
        for(j=0;1<=i-j&&i+j+1<=N;j++) if(A[i-j]==A[i+j+1]) DP[i+j+1]=min(DP[i+j+1],DP[i-j-1]+1); else break;
    }

    cout<<DP[N];
}