#include <bits/stdc++.h>

using namespace std;

struct pos {
    int y, x;
};

int N, M, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char cam[600][600];

void BFS(pos S) {
    queue<pos> Q;
    Q.push(S);
    cam[S.y][S.x] = 'X';

    int ans = 0;
    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            
            if (ny<0||ny>=N||nx<0||nx>=M) continue;
            if (cam[ny][nx] == 'X') continue;
            if (cam[ny][nx] == 'P') ans++;

            cam[ny][nx] = 'X';
            Q.push({ny,nx});
        }
    }

    if (ans) cout << ans;
    else cout << "TT";
}

int main() {
    cin.tie(0);ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    pos S;
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) {
        cin >> cam[y][x];
        if (cam[y][x] == 'I') S = {y,x}; 
    }
    
    BFS(S);
}