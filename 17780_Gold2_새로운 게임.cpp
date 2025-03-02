#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int y, x, r;
} pos;

int         N, K,
            dy[] = {0,0,-1,1}, dx[] = {1,-1,0,0},
            board[14][14];
vector<int> graph[14][14];
vector<pos> player;

bool Play() {
    for (int num = 0; num < K; num++) {
        pos &now = player[num];
        int y = now.y, x = now.x, &r = now.r;
        int ny = y+dy[r], nx = x+dx[r];

        if (graph[y][x][0] != num) continue;

        // white
        if (board[ny][nx] == 0) {
            for (int i : graph[y][x]) {
                graph[ny][nx].push_back(i);
                player[i] = {ny,nx,player[i].r};
            }
            graph[y][x].clear();
        }
        // red
        else if (board[ny][nx] == 1) {
            reverse(graph[y][x].begin(),graph[y][x].end());
            for (int i : graph[y][x]) {
                graph[ny][nx].push_back(i);
                player[i] = {ny,nx,player[i].r};
            }
            graph[y][x].clear();
        }
        // blue
        else if (board[ny][nx] == 2) {
            if (r%2) r--;
            else r++;
            ny = y+dy[r], nx = x+dx[r];
            
            // white
            if (board[ny][nx] == 0) {
                for (int i : graph[y][x]) {
                    graph[ny][nx].push_back(i);
                    player[i] = {ny,nx,player[i].r};
                }
                graph[y][x].clear();
            }
            // red
            else if (board[ny][nx] == 1) {
                reverse(graph[y][x].begin(),graph[y][x].end());
                for (int i : graph[y][x]) {
                    graph[ny][nx].push_back(i);
                    player[i] = {ny,nx,player[i].r};
                }
                graph[y][x].clear();
            }
        }

        if (graph[ny][nx].size() >= 4) return true;
    }    

    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < 14; i++) for (int j = 0; j < 14; j++) board[i][j] = 2; // memset을 절대로 믿지마...
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) cin >> board[i][j];
    for (int i = 0; i < K; i++) {
        int y, x, r; cin >> y >> x >> r;
        player.push_back({y,x,r-1});
        graph[y][x].push_back(i);
    }

    int T = 0;
    while (++T <= 1000) {
        if (Play()) break;
    }

    if (T == 1001) cout << -1;
    else cout << T;
}