#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int N, M,
    visited[50][50],
    dy[] = {1,1,1,0,-1,-1,-1,0}, dx[] = {-1,0,1,1,1,0,-1,-1}, 
    ans = 0;
queue<pair<int,int>> babyShark;

void BFS(pair<int,int> start) {
    queue<pair<int,int>> Q;
    Q.push(start);
    visited[start.first][start.second] = 0;

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();
        
        for (int i = 0; i < 8; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (!(fy<0||fy>=N||fx<0||fx>=M) && visited[fy][fx] > visited[y][x]+1) {
                visited[fy][fx] = visited[y][x]+1;
                Q.push({fy,fx});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        int t; cin >> t;
        if (t) babyShark.push({i,j});
        visited[i][j] = INF;
    }

    while (!babyShark.empty()) {
        BFS(babyShark.front());
        babyShark.pop();
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
        ans = max(ans, visited[i][j]);

    cout << ans;
}