#include <iostream>
#include <queue>
using namespace std;

typedef struct _pos {
    int y, x;

    bool operator== (_pos a) {
        return (y==a.y)&&(x==a.x);
    }
} pos;
typedef pair<pos,pos> ppp;

int N, M;
char board[10][10];
int vis[10][10][10][10];
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
ppp S;

int BFS() {
    queue<ppp> Q; Q.push(S);
    vis[S.first.y][S.first.x][S.second.y][S.second.x] = 1;

    while (!Q.empty()) {
        pos R = Q.front().first, B = Q.front().second;
        Q.pop();

        if (board[R.y][R.x] == 'O') return vis[R.y][R.x][B.y][B.x]-1;

        for (int i = 0; i < 4; i++) {
            pos nR = {R.y+dy[i],R.x+dx[i]}, nB = {B.y+dy[i],B.x+dx[i]};
            if (board[nR.y][nR.x] == '#') nR = R; // 벽 부딛힘
            if (board[nB.y][nB.x] == '#') nB = B;
            if (nR == nB) nR = R, nB = B; // 겹침

            if (vis[nR.y][nR.x][nB.y][nB.x]) continue;
            if (board[nB.y][nB.x] == 'O') continue;

            Q.push({nR,nB});
            vis[nR.y][nR.x][nB.y][nB.x] = vis[R.y][R.x][B.y][B.x]+1;
        }

    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) {
        char c; cin >> c;
        if (c == 'R')       S.first = {y,x};
        else if (c == 'B')  S.second = {y,x};
        board[y][x] = c;
    }

    cout << BFS();
}