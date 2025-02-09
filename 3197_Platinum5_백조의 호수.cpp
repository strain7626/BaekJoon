#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int R, C;
char graph[1500][1500];
bool visited[1500][1500];
pair<int,int> L1, L2;
queue<pair<int,int>> X, L;
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int result = 0;

void Input() {
    cin.tie(0);
    cin >> R >> C;

    vector<pair<int,int>> tempL;

    for (int i=0;i<R;i++) for (int j=0;j<C;j++) {
        cin >> graph[i][j];
        if (graph[i][j] == 'L') {
            graph[i][j] = '.';
            tempL.push_back({i,j});
        }
    }

    L1 = tempL[0];
    L2 = tempL[1];
}

bool lineout(int y, int x) {
    if (y<0||y>=R||x<0||x>=C) return true;
    else return false;
}

bool BFS(pair<int,int> start) {
    queue<pair<int,int>> Q;
    Q.push(start);

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        if (y == L2.first && x == L2.second) return true;

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!lineout(fy,fx) && graph[fy][fx] == '.' && !visited[fy][fx]) {
                Q.push({fy,fx});
                visited[fy][fx] = true;
            }
            if (!lineout(fy,fx) && graph[fy][fx] == 'x' && !visited[fy][fx]) {
                L.push({fy,fx});
                visited[fy][fx] = true;
            }
        }
    }

    return false;
}

void Melt(pair<int,int> target) {
    int y = target.first, x = target.second;
    graph[y][x] = '.';

    for (int i = 0; i < 4; i++) {
        int fy = y+dy[i], fx = x+dx[i];

        if (!lineout(fy,fx) && graph[fy][fx] == 'X') {
            X.push({fy,fx});
            graph[fy][fx] = 'x';
        }
    }
}

void SetIce() {
    for (int y=0;y<R;y++) for (int x=0;x<C;x++) if (graph[y][x] == 'X') {
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (!lineout(fy,fx) && graph[fy][fx] == '.') {
                X.push({y,x});
                graph[y][x] = 'x';
                break;
            }
        }
    }
}

void Solve() {
    L.push(L1);
    SetIce();

    while (true) {
        int t = L.size();
        while (t--) { 
            if (BFS(L.front())) return; 
            L.pop();
        }
        
        t = X.size();
        while (t--) {
            Melt(X.front());
            X.pop();
        }

        result++;
    }
}

int main() {
    Input();
    Solve();
    cout << result;
}