#include <bits/stdc++.h>

using namespace std;

struct pos{int y,x;};

int R, C, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char graph[20][20];
bool vis[26];

int DFS(pos now) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int y = now.y+dy[i], x = now.x+dx[i];
        if (y<0||y>=R||x<0||x>=C) continue;
        if (vis[graph[y][x]-'A']) continue;

        vis[graph[y][x]-'A'] = 1;
        ans = max(ans,DFS({y,x}));
        vis[graph[y][x]-'A'] = 0;
    }
    return ans+1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++)
        cin >> graph[r][c];
    
    vis[graph[0][0]-'A'] = 1;
    cout << DFS({0,0});
}