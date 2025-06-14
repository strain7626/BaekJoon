#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int y, x;
} pos;

int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

int R, C, N;
char cave[100][100];
int vis[100][100];

bool BFS(pos start, int t) {
    bool flag = false; // 땅에 닿아 있는지 여부

    queue<pos> Q;
    Q.push(start);
    vis[start.y][start.x] = t;

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        if (y == R-1) flag = true;

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            
            if (fy<0||fy>=R||fx<0||fx>=C) continue;
            if (cave[fy][fx] == '.') continue;
            if (vis[fy][fx]) continue;

            vis[fy][fx] = t;
            Q.push({fy,fx});
        }
    }

    return flag;
}

void drop(pos start) {
    int t = vis[start.y][start.x];

    // 각 열의 가장 밑 부분을 찾아서 떨어뜨릴 높이 구하기
    int h = 2e9;
    for (int x = 0; x < C; x++) for (int y = R-1; y >= 0; y--) if (vis[y][x] == t) {
        int tmp_h;
        for (tmp_h = 1; (y+tmp_h+1) < R; tmp_h++) {
            if (cave[y+tmp_h+1][x] == 'x') break;
        }
        h = min(h, tmp_h);
        break;
    }

    // 클러스터를 떨어뜨리기
    for (int x = 0; x < C; x++) for (int y = R-1; y >= 0; y--) if (vis[y][x] == t) {
        cave[y][x] = '.';
        cave[y+h][x] = 'x';
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> R >> C;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) cin >> cave[r][c];

    cin >> N;
    for (int i = 0; i < N; i++) {
        int y, x; cin >> y;
        y = R-y;

        bool flag = false;
        for (x = (i%2 ? C-1 : 0); (i%2 ? x >= 0 : x < C); (i%2 ? x-- : x++)) if (cave[y][x] == 'x') {
            cave[y][x] = '.';
            flag = true;
            break;
        }

        if (!flag) continue;
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            
            if (cave[fy][fx] == '.') continue;
            if (vis[fy][fx]) continue;
            if (BFS({fy,fx}, i+1)) continue;

            drop({fy,fx});
            break;
        }
        
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) vis[r][c] = 0;
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) cout << cave[r][c];
        cout << "\n";
    }
}