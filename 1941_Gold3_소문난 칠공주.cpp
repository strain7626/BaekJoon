#include <iostream>
#include <queue>

using namespace std;

int graph[5][5];
bool visited[5][5];

int score = 0;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void Input() {
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
        char c;
        cin >> c;
        if (c == 'Y') graph[i][j] = 0;
        else graph[i][j] = 1;
    }
}

bool lineout(int y, int x) {
    if (y<0||y>=5||x<0||x>=5) return true;
    else return false;
}

bool isConnected(int y, int x) {
    queue<pair<int,int>> myQ;
    myQ.push({y,x});
    int length = 1;
    bool _visited[5][5];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) _visited[i][j] = visited[i][j]; 
    _visited[y][x] = false;

    while (!myQ.empty()) {
        int qy = myQ.front().first, qx = myQ.front().second;
        myQ.pop();
        for (int i = 0; i < 4; i++) {
            if (!lineout(qy+dy[i],qx+dx[i]) && _visited[qy+dy[i]][qx+dx[i]]) {
                _visited[qy+dy[i]][qx+dx[i]] = false;
                length++;
                myQ.push({qy+dy[i],qx+dx[i]});
            }
        }
    }
    if (length == 7) return true;
    else return false;
}

void DFS(int y, int x, int cnt, int s) {
    if (cnt == 7) {
        if (s>=4 && isConnected(y,x)) score++; return;
    }

    for (int i = y; i < 5; i++) for (int j = (i==y ? x+1 : 0); j < 5; j++) {
        visited[i][j] = true;
        DFS(i,j,cnt+1,s+(graph[i][j]==1));
        visited[i][j] = false;
    }

}

int main() {
    Input();
    DFS(0,-1,0,0);
    cout << score;
}