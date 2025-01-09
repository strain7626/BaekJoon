#include <iostream>
#include <queue>

using namespace std;

int R, C;
int graph[1000][1000];
bool visited[1000][1000];
int n_fireQ;
int n_myQ;
queue<pair<int,int>> fireQ;
queue<pair<int,int>> myQ;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input() {
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            if (c == '#') graph[i][j] = 1;
            else if (c == '.') graph[i][j] = 0;
            else if (c == 'F') {
                graph[i][j] = -1;
                fireQ.push({i,j});
                n_fireQ++;
            }
            else if (c == 'J') {
                graph[i][j] = 0;
                myQ.push({i,j});
                n_myQ++;
                visited[i][j] = true;
            }
        }
}

bool outline(int y, int x) {
    if (y == 0 || y == R-1 || x == 0 || x == C-1) return true;
    else return false;
}

bool lineout(int y, int x) {
    if (y < 0 || y > R-1 || x < 0 || x > C-1) return true;
    else return false;
}

void BFS() {
    int time = 1;
    while (true) {
        //불 퍼짐
        int t = n_fireQ;
        n_fireQ = 0;
        while (t--) {
            int fY = fireQ.front().first;
            int fX = fireQ.front().second;
            fireQ.pop();

            for (int i = 0; i < 4; i++)
                if (!lineout(fY+dy[i], fX+dx[i]) && graph[fY+dy[i]][fX+dx[i]] == 0) {
                    graph[fY+dy[i]][fX+dx[i]] = -1;
                    fireQ.push({fY+dy[i],fX+dx[i]});
                    n_fireQ++;
                }
        }
        t = n_myQ;
        n_myQ = 0;
        //지훈이 이동
        while (t--) {
            int jY = myQ.front().first;
            int jX = myQ.front().second;
            myQ.pop();
            
            for (int i = 0; i < 4; i++)
                if (outline(jY, jX)) {
                    cout << time;
                    return;
                }
                else if (graph[jY+dy[i]][jX+dx[i]] == 0 && !visited[jY+dy[i]][jX+dx[i]]) {
                    myQ.push({jY+dy[i], jX+dx[i]});
                    n_myQ++;
                    visited[jY+dy[i]][jX+dx[i]] = true;
                }
        }

        if (!n_myQ) {
            cout << "IMPOSSIBLE";
            return;
        }

        time++;
    }
}

int main() {
    Input();
    BFS();
    return 0;
}