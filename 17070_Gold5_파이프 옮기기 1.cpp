#include <iostream>
#define endl "\n"
using namespace std;

int N, graph[17][17];
int DP[17][17][3];
int result;

void Input() {
    cin >> N;
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++)
        cin >> graph[i][j];
}

void Solve() {
    DP[1][2][0] = 1;

    for (int sum = 4; sum <= N+N; sum++) { // 합이 4인 대각선부터 시작

        // 시작, 끝 정하기
        int start_x = (sum <= N ? 1 : sum - N);
        int end_x = (sum <= N ? sum-1 : N);
    
        for (int x = start_x; x <= end_x; x++) {
            int y = sum - x;

            // 벽
            if (graph[y][x] == 1) continue;

            // 가로
            DP[y][x][0] = DP[y][x-1][0] + DP[y][x-1][2];

            // 세로
            DP[y][x][1] = DP[y-1][x][1] + DP[y-1][x][2];

            // 대각선
            if (graph[y-1][x] == 1 || graph[y][x-1] == 1) continue;
            DP[y][x][2] = DP[y-1][x-1][0] + DP[y-1][x-1][1] + DP[y-1][x-1][2];
        }
    }

    result = DP[N][N][0] + DP[N][N][1] + DP[N][N][2];
}

int main() {
    Input();
    Solve();
    cout << result;
}