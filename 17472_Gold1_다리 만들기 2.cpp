#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, graph[10][10], E[7][7], uni[7] = {0,1,2,3,4,5,6};
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
int t = 0;

void drawGraph(int sy, int sx, int t) {
    queue<pair<int,int>> Q;
    graph[sy][sx] = t;
    Q.push({sy,sx});

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (fy<0||fy>=N||fx<0||fx>=M) continue;
            if (graph[fy][fx] != -1) continue;
            
            graph[fy][fx] = t;
            Q.push({fy,fx});
        }
    }
}

int uni_find(int now) {
    if (now == uni[now]) return now;
    return uni[now] = uni_find(uni[now]);
}

int Kruskal() {
    int result = 0;

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> PQ;
    for (int i = 1; i <= t; i++) for (int j = 1; j <= t; j++) if (E[i][j] != 2e9) PQ.push({E[i][j],{i,j}});

    while (!PQ.empty()) {
        int cost = PQ.top().first, a = PQ.top().second.first, b = PQ.top().second.second;
        a = uni_find(a); b = uni_find(b);
        if (a != b) {
            result += cost;
            uni[b] = a;
        } 
        PQ.pop();
    }

    for (int i = 2; i <= t; i++) if (uni_find(1) != uni_find(i)) return -1;

    return result;
}

int main() {
    for (int i = 1; i <= 6; i++) for (int j = 1; j <= 6; j++) E[i][j] = 2e9;

    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> graph[i][j]; graph[i][j] *= -1;
    }

    // 섬 개수 카운트 및 구분
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (graph[i][j] == -1)
        drawGraph(i,j,++t);

    // 다리 긋기 (최솟값만 남김)
    // 가로
    for (int y = 0; y < N; y++) for (int x = 0; x < M-2; x++) {
        if (graph[y][x] && !graph[y][x+1] && !graph[y][x+2]) {
            int t1 = graph[y][x];

            for (int x2 = x+3; x2 < M; x2++) if (graph[y][x2]) {
                int t2 = graph[y][x2];

                if (t1 != t2) E[t1][t2] = min(E[t1][t2], x2-x-1);
                break;
            }
        }
    }
    // 세로
    for (int y = 0; y < N-2; y++) for (int x = 0; x < M; x++) {
        if (graph[y][x] && !graph[y+1][x] && !graph[y+2][x]) {
            int t1 = graph[y][x];
            
            for (int y2 = y+3; y2 < N; y2++) if (graph[y2][x]) {
                int t2 = graph[y2][x];
                
                if (t1 != t2) E[t1][t2] = min(E[t1][t2], y2-y-1);
                break;
            }
        }
    }
    
    std::cout << Kruskal() << '\n';
}