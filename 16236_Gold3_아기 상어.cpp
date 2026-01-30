#include <bits/stdc++.h>

using namespace std;

struct pos {int y,x;};

int N, siz = 2, cnt = 2, graph[20][20], vis[20][20], dy[] = {-1,0,0,1}, dx[] = {0,-1,1,0};

int BFS(pos start) {
    queue<pos> Q; Q.push(start);

    pos nxt = {N,N};
    int ans = 0;
    bool eat = 0;

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x; Q.pop();
        
        if (eat && vis[nxt.y][nxt.x] == vis[y][x]) {
            while (!Q.empty()) Q.pop();
            Q.push(nxt);

            int tmp = vis[nxt.y][nxt.x];
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) vis[i][j] = 0;
            vis[nxt.y][nxt.x] = tmp;
            graph[nxt.y][nxt.x] = 0;

            eat = 0;
            nxt = {N,N};

            if (!--cnt) cnt = ++siz;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];

            if (ny<0||ny>=N||nx<0||nx>=N) continue;
            if (graph[ny][nx] > siz) continue;
            if (vis[ny][nx]) continue;

            if (graph[ny][nx] && graph[ny][nx] < siz) {
                eat = 1;
                ans = vis[y][x];
                if (ny < nxt.y || (ny==nxt.y && nx<nxt.x)) nxt = {ny,nx};
            }
            
            vis[ny][nx] = vis[y][x]+1;
            Q.push({ny,nx});
        }

    }

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    pos start;
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int x; cin >> x;
        if (x==9) { start = {i,j}; vis[i][j] = 1; x = 0; }
        graph[i][j]=x;
    }

    cout << BFS(start);
}