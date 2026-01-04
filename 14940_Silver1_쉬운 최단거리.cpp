#include <bits/stdc++.h>

using namespace std;

struct pos {
    int y, x;
};

int n, m, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
vector<vector<int>> vis;

void BFS(pos S) {
    queue<pos> Q; Q.push(S);

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];

            if (ny<0||ny>=n||nx<0||nx>=m) continue;
            if (vis[ny][nx] != -1) continue;
            
            vis[ny][nx] = vis[y][x]+1;
            Q.push({ny,nx});
        }
    }
}

int main() {
    cin.tie(0);ios::sync_with_stdio(0);

    pos S;
    cin >> n >> m; vis.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int t; cin >> t;
        if (t == 2) { t = 0; S = {i,j}; }
        vis[i][j]=-t;
    }  
    
    BFS(S);
    for (int i = 0; i < n; i++) { for (int j = 0; j < m; j++) cout << vis[i][j] << ' '; cout << '\n'; }
}