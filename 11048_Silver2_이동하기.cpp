#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;

int N, M, graph[1001][1001], DP[1001][1001];
int result;
void Input() {
    cin >> N >> M;
    for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) 
        cin >> graph[i][j];
}

int max(int arr[3]) {
    int M = 0;
    for (int i=0;i<3;i++) if (arr[i] > M)
        M = arr[i];
    return M;
}
int DFS() {
    stack<pair<int,int>> S;
    S.push({1,1});

    while (!S.empty()) {
        int y = S.top().first, x = S.top().second;
        S.pop();

        if(y == 1 && x < M) S.push({y,x+1});
        if(y < N) S.push({y+1,x});

        int temp[3] = {DP[y-1][x], DP[y-1][x-1], DP[y][x-1]};
        DP[y][x] = max(temp) + graph[y][x];
    }

    return DP[N][M];
}
void Solve() {
    result = DFS();
}

int main() {
    Input();
    Solve();
    cout << result;
}