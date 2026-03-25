#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MOD=1e9+7;

ll N,DP[3][3]={{1,0,0},{0,1,0},{0,0,1}},ans[3][3];

void mul(ll A[3][3],ll B[3][3],ll (*C)[3]) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) for(int l=0;l<3;l++) C[i][l]+=A[i][j]*B[k][l]*(j&&j==k?2:1)%MOD,C[i][l]%=MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;

    if(N&1) {cout<<0;return 0;}

    bool chk=0;
    while(N/=2) {
        if(N&1) if(!chk) {
            chk=1;
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) ans[i][j]=DP[i][j];
        } else {
            ll tmp[3][3]={{0,0,0},{0,0,0},{0,0,0}};
            mul(DP,ans,tmp);
            for(int i=0;i<3;i++) for(int j=0;j<3;j++) ans[i][j]=tmp[i][j];
        }
        
        ll tmp[3][3]={{0,0,0},{0,0,0},{0,0,0}};
        mul(DP,DP,tmp);
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) DP[i][j]=tmp[i][j];
    }
    
    ll sum=0;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) sum=(sum+ans[i][j])%MOD;
    cout<<sum;
}