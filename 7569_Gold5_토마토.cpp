#include <iostream>
#include <queue>
using namespace std;

typedef struct _pos {
    int z, y, x;
} pos;

int         N, M, H, graph[100][100][100],
            dz[] = {-1,1,0,0,0,0}, dy[] = {0,0,-1,1,0,0}, dx[] = {0,0,0,0,-1,1};
queue<pos>  Q;
int         ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> M >> N >> H;
    for (int i=0;i<H;i++) for (int j=0;j<N;j++) for (int k=0;k<M;k++) {
        cin >> graph[i][j][k];
        if (graph[i][j][k] == 1) Q.push({i,j,k});
    }

    while(!Q.empty()) {
        int z = Q.front().z, y = Q.front().y, x = Q.front().x;
        Q.pop();
        
        for (int i = 0; i < 6; i++) {
            int fz = z+dz[i], fy = y+dy[i], fx = x+dx[i];

            if (!(fz<0||fz>=H||fy<0||fy>=N||fx<0||fx>=M) && graph[fz][fy][fx] == 0) {
                graph[fz][fy][fx] = graph[z][y][x] + 1;
                Q.push({fz,fy,fx});
            }
        }
    }

    for (int i=0;i<H;i++) for (int j=0;j<N;j++) for (int k=0;k<M;k++) {
        if (graph[i][j][k] == 0) {cout << -1;return 0;}
        ans = (graph[i][j][k] > ans ? graph[i][j][k] : ans);
    }

    cout << ans-1;
}