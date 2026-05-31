#include <bits/stdc++.h>

using namespace std;

int DP[3030][3030];
string S;

void solve() {
    cin>>S;
    int L=S.size();
    for(int i=0;i<L;i++) for(int j=0;j<L;j++) DP[i][j]=1e9;
    DP[0][L-1]=0;

    for(int l=L-1;l>0;l--) {
        for(int i=0;i+l<L;i++) {
            DP[i+1][i+l]=min(DP[i+1][i+l],DP[i][i+l]+1);
            DP[i][i+l-1]=min(DP[i][i+l-1],DP[i][i+l]+1);
            DP[i+1][i+l-1]=min(DP[i+1][i+l-1],DP[i][i+l]+(S[i]!=S[i+l]));
        }
    }
    
    int m=1e9;
    for(int i=0;i<L;i++) m=min(m,DP[i][i]);
    for(int i=1;i<L;i++) m=min(m,DP[i][i-1]);
    cout<<m<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;cin>>t;while(t--) solve();
}