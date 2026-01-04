#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, M, DP[501][501];

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) DP[i][j] = INF;
    while (M--) {
        int u, v; cin >> u >> v;
        DP[u][v] = 1, DP[v][u] = 1;
    }

    for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
        DP[i][j] = min(DP[i][j], DP[i][k]+DP[k][j]);
    
    int ans, m = INF;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) if(i!=j) tmp += DP[i][j];
        if (tmp < m) {
            m = tmp;
            ans = i;
        }
    }

    cout << ans;
}