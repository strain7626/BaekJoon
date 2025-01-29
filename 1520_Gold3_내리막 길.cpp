#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;

int M, N, graph[500][500];
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int DP[500][500];
int result = 0;

void Input() {
    cin >> M >> N;
    for (int i=0;i<M;i++) for (int j=0;j<N;j++) {
        cin >> graph[i][j];
        DP[i][j] = -1;
    }
}

bool lineout(int y, int x) {
    if (y<0 || y>=M || x<0 || x>=N) return true;
    else return false;
}

int DFS(int y, int x) {
    if (y == M-1 && x == N-1) return 1;
    if (DP[y][x] != -1) return DP[y][x];

    DP[y][x] = 0;

    for (int i = 0; i < 4; i++) {
        int fy = y+dy[i], fx = x+dx[i];
        if (!lineout(fy,fx) &&  graph[y][x] > graph[fy][fx]) 
            DP[y][x] += DFS(fy,fx);
    }

    return DP[y][x];
}

void Solve() {
    result = DFS(0,0);
}



int main() {
    Input();
    Solve();
    cout << result;
}