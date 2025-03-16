#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef struct {
    int y, x;
} pos;

int  N, M;
char graph[50][50];
int  vis[50][50][1<<6];
int  dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
pos  ori_start;

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> graph[i][j];
        if (graph[i][j] == '0') {
            ori_start = {i,j};
            graph[i][j] = '.';
        }
        for (int k = 0; k < (1<<6); k++) vis[i][j][k] = INF;
    }
}

int BFS(pos start, int key, int dist) {
    queue<pos> Q;
    Q.push(start);
    vis[start.y][start.x][key] = dist;

    int ans = INF;

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            char c = graph[fy][fx];
            
            if (fy<0||fy>=N||fx<0||fx>=M) continue;
            if (vis[fy][fx][key] <= vis[y][x][key]+1) continue;
            if (c == '#' || ((c>='A'&&c<='F') && !(key & (1<<(c-'A'))))) continue;
            
            Q.push({fy,fx});
            vis[fy][fx][key] = vis[y][x][key]+1;
            
            if (c == '1') 
                ans = min(ans, vis[fy][fx][key]);
            else if ((c>='a'&&c<='f') && !(key & (1<<(c-'a')))) 
                ans = min(ans, BFS({fy,fx}, key|(1<<(c-'a')), vis[fy][fx][key]));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    int ans = BFS(ori_start,0,0);
    cout << (ans == INF ? -1 : ans);
}