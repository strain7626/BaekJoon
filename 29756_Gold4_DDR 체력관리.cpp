#include <iostream>

using namespace std;

int N, K, S[1000], H[1000];
int DP[1000][101];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) for (int j = 0; j <= 100; j++) DP[i][j] = 0;
    
    DP[0][100-H[0]] = S[0];
    for (int i = 0; i < N-1; i++) for (int j = 0; j <= 100; j++) {
        if (!DP[i][j] && j != 100) continue;
        
        int t = (j+K<=100 ? j+K : 100);
        DP[i+1][t] = max(DP[i+1][t], DP[i][j]);
        if (t-H[i+1] >= 0) DP[i+1][t-H[i+1]] = max(DP[i+1][t-H[i+1]], DP[i][j] + S[i+1]);
    }
    
    int ans = 0;
    for (int i : DP[N-1]) ans = max(ans, i);
    cout << ans;
}