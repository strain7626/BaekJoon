#include <iostream>
#include <queue>
#define HEIGHT 12
#define WIDTH 6
using namespace std;

char    graph[12][6];
bool    visited[12][6];
int     dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
bool    isBombed;
int     ans;

void Input() {
    for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) 
        cin >> graph[i][j];
}   

bool lineout(int y, int x) {
    if (y<0||y>=12||x<0||x>=6) return true;
    return false;
}

void Bomb(int _y, int _x) {
    isBombed = true;

    queue<pair<int,int>> Q;
    Q.push({_y,_x});

    char myType = graph[_y][_x];
    graph[_y][_x] = '.';
    
    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!lineout(fy,fx) && graph[fy][fx] == myType) {
                Q.push({fy,fx});
                graph[fy][fx] = '.';
            }
        }
    }
}

void BFS(int _y, int _x) {
    queue<pair<int,int>> Q;
    Q.push({_y,_x});
    
    char myType = graph[_y][_x];
    int cnt = 1;
    visited[_y][_x] = 1;

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!lineout(fy,fx) && !visited[fy][fx] && graph[fy][fx] == myType) {
                Q.push({fy,fx});
                visited[fy][fx] = 1;
                cnt++;
            }
        }
    }

    if (cnt >= 4) {
        Bomb(_y,_x);
    }

}

void Fall() {
    for (int x = 0; x < 6; x++) {
        for (int y = 11; y > 0; y--) {
            if (graph[y][x] != '.') continue;

            for (int i = y-1; i >= 0; i--) {
                if (graph[i][x] != '.') {
                    swap(graph[y][x], graph[i][x]);
                    break;
                }
            }
        }
    }
}

void Solve() {
    ans = -1;
    isBombed = true;
    while (isBombed) {
        ans++;
        isBombed = false;
        for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) 
            if (!visited[i][j] && graph[i][j] != '.') BFS(i,j);
        Fall();
        for (int i = 0; i < 12; i++) for (int j = 0; j < 6; j++) visited[i][j] = 0; 
    }
}

int main() {
    Input();
    Solve();
    cout << ans;
}