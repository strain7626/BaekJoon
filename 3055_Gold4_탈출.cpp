#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

int R, C, t_graph[50][50];
char graph[50][50];
bool vis[50][50];

typedef struct {
    int y,x;
} pos;
pos D, S;
queue<pos> Q;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) t_graph[i][j] = 2e9;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        char c; cin >> c;
        graph[i][j] = c;
        if (c == '*') {Q.push({i,j}); t_graph[i][j] = 0;}
        else if (c == 'D') D = {i,j};
        else if (c == 'S') S = {i,j};
    }

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (fy<0||fy>=R||fx<0||fx>=C) continue;
            if (graph[fy][fx] != '.' && graph[fy][fx] != 'S') continue;
            if (t_graph[fy][fx] != 2e9) continue;

            t_graph[fy][fx] = t_graph[y][x]+1;
            Q.push({fy,fx});
        }
    }

    int t = 0, n_t = 1;
    Q.push(S);
    vis[S.y][S.x] = 1;

    while (!Q.empty()) {
        if (n_t == 0) {
            t++;
            n_t = Q.size();
        }
        n_t--;

        int y = Q.front().y, x = Q.front().x;
        Q.pop();


        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (D.y == fy && D.x == fx) {cout << t+1; exit(0);}

            if (fy<0||fy>=R||fx<0||fx>=C) continue;
            if (t_graph[fy][fx] <= t+1) continue;
            if (graph[fy][fx] != '.') continue;
            if (vis[fy][fx]) continue;

            vis[fy][fx] = 1;
            Q.push({fy,fx});
        }
    }
    
    cout << "KAKTUS";
}