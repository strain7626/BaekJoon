#include <iostream>
#include <queue>
using namespace std;

typedef struct _pos {
    int y, x;
} pos;

int         N, M, graph[1000][1000],
            dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
queue<pos>  Q;
int         ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> M >> N;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
        cin >> graph[i][j];
        if (graph[i][j] == 1) Q.push({i,j});
    }

    while(!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!(fy<0||fy>=N||fx<0||fx>=M) && graph[fy][fx] == 0) {
                graph[fy][fx] = graph[y][x] + 1;
                Q.push({fy,fx});
            }
        }
    }

    for (int i=0;i<N;i++) for (int j=0;j<M;j++) {
        if (graph[i][j] == 0) {cout << -1;return 0;}
        ans = (graph[i][j] > ans ? graph[i][j] : ans);
    }

    cout << ans-1;
}