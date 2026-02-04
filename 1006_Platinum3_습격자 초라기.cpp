#include <bits/stdc++.h>

using namespace std;

int N,W,E[10000][2],DP[10000][3];

void solve() {
    for (int i=2;i<N;i++) {
        bool a=E[i-1][0]+E[i][0]<=W,b=E[i-1][1]+E[i][1]<=W;
        DP[i][0]=DP[i-1][2]+1;
        if (a) DP[i][0]=min(DP[i][0],DP[i-1][1]+1);
        DP[i][1]=DP[i-1][2]+1;
        if (b) DP[i][1]=min(DP[i][1],DP[i-1][0]+1);

        DP[i][2]=min(DP[i][0],DP[i][1])+1;
        if (a&&b) DP[i][2]=min(DP[i][2],DP[i-2][2]+2);
        if (E[i][0]+E[i][1]<=W) DP[i][2]=min(DP[i][2],DP[i-1][2]+1);

        // DP[i][0]=(a?DP[i-1][1]:DP[i-1][2])+1;
        // DP[i][1]=(b?DP[i-1][0]:DP[i-1][2])+1;
        // DP[i][2]=(a&&b?DP[i-2][2]+2:E[i][0]+E[i][1]<=W?DP[i-1][2]+1:min(DP[i][0],DP[i][1])+1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T; while (T--) {
        cin >> N >> W;
        for (int i=0;i<N;i++) cin >> E[i][0];
        for (int i=0;i<N;i++) cin >> E[i][1];

        bool a=E[0][0]+E[1][0]<=W,b=E[0][1]+E[1][1]<=W;
        DP[0][2]=(E[0][0]+E[0][1]<=W?1:2);
        DP[1][0]=(a?2:DP[0][2]+1);
        DP[1][1]=(b?2:DP[0][2]+1);
        DP[1][2]=(a&&b?2:E[1][0]+E[1][1]<=W?DP[0][2]+1:min(DP[1][0],DP[1][1])+1);
        solve();
        int ans=DP[N-1][2];

        if (E[N-1][0]+E[0][0]<=W) {
            DP[0][2]=1;
            DP[1][0]=2;
            DP[1][1]=(E[0][1]+E[1][1]<=W?1:2);
            DP[1][2]=min(DP[1][1]+1,E[1][0]+E[1][1]<=W?2:3);
            solve();
            ans=min(ans,DP[N-1][1]+1);
        }
        if (E[N-1][1]+E[0][1]<=W) {
            DP[0][2]=1;
            DP[1][1]=2;
            DP[1][0]=(E[0][0]+E[1][0]<=W?1:2);
            DP[1][2]=min(DP[1][0]+1,E[1][0]+E[1][1]<=W?2:3);
            solve();
            ans=min(ans,DP[N-1][0]+1);
        }
        if (E[N-1][0]+E[0][0]<=W&&E[N-1][1]+E[0][1]<=W) {
            DP[0][2]=0;
            DP[1][1]=1;
            DP[1][0]=1;
            DP[1][2]=(E[1][0]+E[1][1]<=W?1:2);
            solve();
            ans=min(ans,DP[N-2][2]+2);
        }
        cout << (N==1?E[0][0]+E[0][1]<=W?1:2:ans) << '\n';
    }
}