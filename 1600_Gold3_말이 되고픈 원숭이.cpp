#include <iostream>
#include <queue>

using namespace std;

int K, W, H, graph[200][200];
int visited[200][200][31];

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int hx[] = {-1,1,2,2,1,-1,-2,-2}, hy[] = {2,2,1,-1,-2,-2,-1,1};

void Input() {
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
        cin >> graph[i][j];
}

bool lineout(int y, int x) {
    if (x<0||x>=W||y<0||y>=H) return true;
    return false;
}

int BFS() {
    queue<pair<int,int>> myQ;
    queue<int> myK;
    myQ.push({0,0});
    myK.push(K);
    visited[0][0][K] = 1;

    while (!myQ.empty()) {
        int x = myQ.front().second, y = myQ.front().first;
        int k = myK.front();
        myQ.pop();myK.pop();
        
        if (x == W-1 && y == H-1) return visited[x][y][k]-1;

        for (int i = 0; i < 4; i++) 
            if (!lineout(y+dy[i],x+dx[i]) && !visited[y+dy[i]][x+dx[i]][k] && !graph[y+dy[i]][x+dx[i]]) {
                myQ.push({y+dy[i],x+dx[i]});
                myK.push(k);
                visited[y+dy[i]][x+dx[i]][k] = visited[y][x][k]+1;
            }

        if (k) {
            k--;
            for (int i = 0; i < 8; i++)
                if (!lineout(y+hy[i],x+hx[i]) && !visited[y+hy[i]][x+hx[i]][k] && !graph[y+hy[i]][x+hx[i]]) {
                    myQ.push({y+hy[i],x+hx[i]});
                    myK.push(k);
                    visited[y+hy[i]][x+hx[i]][k] = visited[y][x][k+1]+1;
                }
        }
    }

    return -1;
}

int main() {
    Input();
    cout << BFS();

    return 0;
}