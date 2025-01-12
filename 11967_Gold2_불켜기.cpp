#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool graph[102][102];
bool visited[102][102];
bool BFSvisited[102][102];

vector<pair<int,int>> button[101][101];

int result = 0;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void Input() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        button[b][a].push_back({d,c});
    }
}

pair<int,int> BFS() {
    queue<pair<int,int>> myQ;
    myQ.push({1,1});
    
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) BFSvisited[i][j] = graph[i][j];

    while (!myQ.empty()) {
        int y = myQ.front().first, x = myQ.front().second;
        myQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (BFSvisited[fy][fx]) {
                BFSvisited[fy][fx] = false;
                myQ.push({fy,fx});
                if (!visited[fy][fx]) return {fy,fx};
            }
        }
    }
    return {0,0};
}

void TurnLight(int y, int x) {
    for (pair<int,int> i : button[y][x]) {
        graph[i.first][i.second] = true;
    }
}

void Solve() {
    pair<int,int> myP = {1,1};
    graph[1][1] = 1;
    while (myP.first + myP.second) {
        TurnLight(myP.first,myP.second);
        visited[myP.first][myP.second] = 1;
        myP = BFS();
    }
}

void Check() {
    for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) result += graph[i][j];
}

int main() {
    Input();
    Solve();
    Check();
    cout << result;
}