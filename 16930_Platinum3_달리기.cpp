#include <bits/stdc++.h>

using namespace std;

struct pos { int y, x; };

int N, M, K, vis[1001][1001], dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
pos p1, p2;

int BFS(pos S) {
    vis[S.y][S.x] = 1;
    queue<pos> Q; Q.push(S);

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x; Q.pop();

        for (int i = 0; i < 4; i++) for (int k = 1; k <= K; k++) {
            int ny = y+k*dy[i], nx = x+k*dx[i];

            if (ny<1||ny>N||nx<1||nx>M) break;
            if (vis[y][x] >= vis[ny][nx]-1 && vis[ny][nx]) break;
            
            vis[ny][nx] = vis[y][x]+1;
            Q.push({ny,nx});
        }
    }

    return vis[p2.y][p2.x] ? vis[p2.y][p2.x]-1 : -1;
}

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
        char c; cin >> c;
        vis[i][j] = -(c=='#');
    }
    cin >> p1.y >> p1.x >> p2.y >> p2.x;

    cout << BFS(p1);
}