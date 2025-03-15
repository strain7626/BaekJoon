#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M,
    DP[101][101];
vector<int> route[101][101];

void Floyd_Warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
            if (DP[i][j] > DP[i][k] + DP[k][j]) {
                DP[i][j] = DP[i][k] + DP[k][j];
                route[i][j] = route[i][k];
                route[i][j].insert(route[i][j].end(), route[k][j].begin(), route[k][j].end());
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) DP[i][j] = INF;
    for (int i = 1; i <= N; i++) DP[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (DP[a][b] > c) {
            DP[a][b] = c;
            route[a][b] = {a};
        }
    }

    Floyd_Warshall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cout << (DP[i][j] == INF ? 0 : DP[i][j]) << " ";
        cout << endl;
    }
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
        if (DP[i][j] == 0 || DP[i][j] == INF) {cout << 0 << endl; continue;} 
        cout << route[i][j].size()+1 << " ";
        for (int k : route[i][j]) cout << k << " ";
        cout << j << endl;
    }
}