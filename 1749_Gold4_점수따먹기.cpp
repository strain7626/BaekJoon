#include <bits/stdc++.h>
using namespace std;

int N, M;
int DP[201][201];
int ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
        cin >> DP[i][j];
        DP[i][j] += DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1];
    }

    ans = -2e9;
    for (int y1 = 1; y1 <= N; y1++) for (int x1 = 1; x1 <= M; x1++) {
        for (int y2 = 1; y2 <= y1; y2++) for (int x2 = 1; x2 <= x1; x2++) {
            ans = max(ans, DP[y1][x1] - (DP[y2-1][x1] + DP[y1][x2-1] - DP[y2-1][x2-1]));
        }
    }

    cout << ans;
}