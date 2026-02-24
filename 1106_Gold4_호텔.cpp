#include <bits/stdc++.h>

using namespace std;

int C,N,DP[1001],a,b;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for(int i=0;i<=1000;i++) DP[i]=1e9;
    DP[0]=0;
    
    cin>>C>>N;

    for(int i=1;i<=N;i++) {
        cin>>a>>b;
        for(int j=0;j<=C;j++) DP[min(j+b,C)]=min(DP[min(j+b,C)],DP[j]+a);
    }

    cout<<DP[C];
}