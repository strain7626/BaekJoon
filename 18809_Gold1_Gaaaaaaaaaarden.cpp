#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, M, G, R; 
int graph[50][50]; // 3은 초록 4는 빨강
int visited[50][50]; // 음수는 G시간 양수는 R시간
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int flowerCnt;
int result = 0;
int simTime;

deque<pair<int,int>> baseGQ;
deque<pair<int,int>> baseRQ;

deque<pair<int,int>> GQ;
deque<pair<int,int>> RQ;

void Input() {
    cin.tie(0);
    cin >> N >> M >> G >> R;
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) cin >> graph[i][j];
}

void Setting() {
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) visited[i][j] = 0;
    simTime = 0;
    flowerCnt = 0;
    GQ = baseGQ;
    RQ = baseRQ;
}

bool lineout(int y, int x) {
    if (y<0||y>=N||x<0||x>=M) return true;
    else return false;
}

void BFS(char c, deque<pair<int,int>> &Q) {
    int t = Q.size();
    while (t--) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop_front();
        if (visited[y][x] == 2e9) continue;

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (!lineout(fy,fx) && visited[fy][fx] == 0 && (graph[fy][fx] == 1 || graph[fy][fx] == 2)) {
                Q.push_back({fy,fx});
                visited[fy][fx] = simTime;

                if (c == 'G') visited[fy][fx] = -1*visited[fy][fx];
            }

            if (c == 'R' && !lineout(fy,fx) && visited[fy][fx] == -simTime) {
                visited[fy][fx] = 2e9;
                flowerCnt++;
            }
        }
    }
}

void Simulation() {
    Setting();
    while (!GQ.empty() && !RQ.empty()) {
        simTime++;

        BFS('G', GQ);
        BFS('R', RQ);
    }

    if (flowerCnt > result) {
        result = flowerCnt;
    }
}

pair<int,int> FindNext(int y, int x) {
    for (int j = x; j < M; j++) if (graph[y][j] == 2) return {y,j};
    for (int i = y+1; i < N; i++) for (int j = 0; j < M; j++) if (graph[i][j] == 2) return {i,j};
    
    return {-1,-1};
}

void DFS(int y, int x) {
    pair<int,int> next = FindNext(y,x+1);

    // 초록 배양액
    if (G) {
        graph[y][x] = 3;
        baseGQ.push_back({y,x});
        G--;

        if (G == 0 && R == 0) {
            Simulation();
        }

        if (next.first != -1)
            DFS(next.first, next.second);
        
        graph[y][x] = 2;
        baseGQ.pop_back();
        G++;
    }

    // 빨강 배양액
    if (R) {
        graph[y][x] = 4;
        baseRQ.push_back({y,x});
        R--;
        
        if (G == 0 && R == 0) {
            Simulation();
        }

        if (next.first != -1)
            DFS(next.first, next.second);
        
        graph[y][x] = 2;
        baseRQ.pop_back();
        R++;
    }
    

    // 건너뛰기
    if (next.first != -1)
        DFS(next.first, next.second);
}

void Solve() {
    pair<int,int> start = FindNext(0,0);
    DFS(start.first, start.second);
}

int main() {
    Input();
    Solve();
    cout << result;
}
