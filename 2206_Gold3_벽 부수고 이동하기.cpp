#include <iostream>
#include <queue>
using namespace std;

typedef struct _pos {
    int y, x;
} pos;

int     N, M,
        visited[1000][1000],
        dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char    graph[1000][1000];
int     ans;

queue<pos> Q1; // 벽 부수기 전
queue<pos> Q2; // 벽 부순 후

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
        cin >> graph[i][j];
        visited[i][j] = -1;
    }

    Q1.push({0,0});
    visited[0][0] = 1;

    while(!Q1.empty()) {
        int y = Q1.front().y, x = Q1.front().x;
        Q1.pop();
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!(fy<0||fy>=N||fx<0||fx>=M) && visited[fy][fx] == -1) {
                visited[fy][fx] = visited[y][x]+1;
                if (graph[fy][fx] == '0')   Q1.push({fy,fx});
                else                        Q2.push({fy,fx});
            }
        }
    }
    
    while(!Q2.empty()) {
        int y = Q2.front().y, x = Q2.front().x;
        Q2.pop();
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!(fy<0||fy>=N||fx<0||fx>=M) && graph[fy][fx] == '0' && (visited[y][x]+1 < visited[fy][fx] || visited[fy][fx] == -1)) {
                visited[fy][fx] = visited[y][x]+1;
                Q2.push({fy,fx});
            }
        }
    }

    cout << visited[N-1][M-1];
}