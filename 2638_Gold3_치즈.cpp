#include <bits/stdc++.h>

using namespace std;

struct pos{int y,x;};

int N, M, dy[]={-1,1,0,0}, dx[]={0,0,-1,1};
bool G[100][100], vis[100][100];
queue<pos> Q1, Q2;

void check(int y, int x) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) if (!G[y+dy[i]][x+dx[i]] && vis[y+dy[i]][x+dx[i]]) cnt++;
    if (cnt < 2) return;

    Q2.push({y,x});
    vis[y][x] = 1;
}

bool BFS() {
    while (!Q1.empty()) {
        int y = Q1.front().y, x = Q1.front().x;
        Q1.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];

            if (ny<0||ny>=N||nx<0||nx>=M) continue;
            if (vis[ny][nx]) continue;

            if (G[ny][nx]) check(ny,nx);
            else {
                Q1.push({ny,nx});
                vis[ny][nx] = 1;
            }
        }
    }

    if (Q2.empty()) return 0;
    while (!Q2.empty()) {
        G[Q2.front().y][Q2.front().x] = 0;
        Q1.push(Q2.front()); Q2.pop();
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> G[i][j];

    Q1.push({0,0});
    vis[0][0] = 1;

    int ans = 0;
    while (BFS()) {
        ans++;        
    }
    cout << ans;
}