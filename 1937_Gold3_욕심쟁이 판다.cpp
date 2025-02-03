#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, graph[500][500];
int DP[500][500];
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int result;

void Input() {
    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> graph[i][j];
}

bool lineout(int y, int x) {
    if (y<0||y>=N||x<0||x>=N) return true;
    else return false;
}

int DFS(int y, int x) {
    if (DP[y][x]) return DP[y][x];

    for (int i = 0; i < 4; i++) {
        int fy = y+dy[i], fx = x+dx[i];

        if (!lineout(fy, fx) && graph[fy][fx] > graph[y][x])
            DP[y][x] = max(DP[y][x], DFS(fy, fx));
    }

    return DP[y][x] += 1;
}

void Solve() {
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) 
        if (!DP[i][j]) DFS(i, j);
        
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) 
        result = max(result, DP[i][j]);
}

int main() {
    Input();
    Solve();
    cout << result;
}