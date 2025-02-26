#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, A[1000][3], DP[1000][3];

int DFS(int cnt, int RGB) {
    if (DP[cnt][RGB]) return DP[cnt][RGB];
    DP[cnt][RGB] = A[cnt][RGB] + min(DFS(cnt+1,(RGB+1)%3),DFS(cnt+1,(RGB+2)%3));
    return DP[cnt][RGB];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) cin >> A[i][j];

    int ans = INF;
    for (int RGB = 0; RGB < 3; RGB++) {
        memset(DP,0,sizeof(DP));
        DP[N-1][RGB] = INF;
        DP[N-1][(RGB+1)%3] = A[N-1][(RGB+1)%3];
        DP[N-1][(RGB+2)%3] = A[N-1][(RGB+2)%3];
        ans = min(ans,DFS(0,RGB));
    }

    cout << ans;
}