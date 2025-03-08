#include <bits/stdc++.h>
using namespace std;

int N, M, coin[21], DP[10001][21];

int DFS(int val, int c) {
    if (val == M) return 1;

    if (DP[val][c] != -1) return DP[val][c];
    DP[val][c] = 0;

    if (val+coin[c] <= M)
        DP[val][c] += DFS(val+coin[c], c);
    
    if (c+1 <= N)
        DP[val][c] += DFS(val, c+1);

    return DP[val][c];
}

int main() {
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> coin[i];
        cin >> M;
        for (int i = 0; i <= M; i++) for (int j = 1; j <= N; j++) DP[i][j] = -1; 

        cout << DFS(0,1) << endl;    
    }
}