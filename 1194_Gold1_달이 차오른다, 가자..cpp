#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int,int> pos;

/* 입력 */
int         N, M;
char        maze[50][50];

/* Solve 용 */
queue<pos>      startPos;
queue<bool[6]>  haveKey;

/* BFS 용 */
int         visited[50][50];
int         dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

bool canGo(int y, int x) {
    if (y<0||y>=N||x<0||x>=M)   return false; // 범위
    if (visited[y][x] != -1)    return false; // 방문

    char c = maze[y][x];
    if (c == '#')                                           return false; // 벽
    if (c >= 'A' && c <= 'F' && !haveKey.front()[c-'A'])    return false; // 닫힌 문
    
    /* 그 외 */
    return true;
}

// start에서 end로 갈때 최소거리 반환
int BFS(pos start) {
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) visited[i][j] = -1;
    visited[start.first][start.second] = 0;

    queue<pos> Q;
    Q.push(start);

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        if (maze[y][x] == '1') return visited[y][x];
        if (maze[y][x] >= 'a' && maze[y][x] <= 'f' && pos{y,x} != start) startPos.push({y,x});

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (canGo(fy,fx)) {
                visited[fy][fx] = visited[y][x]+1;
                Q.push({fy,fx});
            }
        }
    }
    
    return 2e9;
}

void Input() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
        cin >> maze[i][j];
        if (maze[i][j] == '0') startPos.push({i,j});
    }
}

int Solve() {
    int result = 2e9;

    while(!startPos.empty()) {
        result = min(result, BFS(startPos.front()));
        startPos.pop();
    }
}

int main() {
    Input();
    cout << Solve();
}