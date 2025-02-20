#include <iostream>
#include <queue>
#define INF 2e9
using namespace std;

enum {
    FOWARD,
    BACKWARD
};

int N, M, X;
vector<pair<int,int>> edge[2][1001];
int dist[2][1001];
int ans;

void Input() {
    cin >> N >> M >> X;
    for (int i=0;i<M;i++) {
        int u,v,t; cin >> u >> v >> t;
        edge[FOWARD][u].push_back({v,t});
        edge[BACKWARD][v].push_back({u,t});
    }
}

void Dijkstra(int type) {
    bool visit[1001];
    for (int i = 1; i <= N; i++) {
        dist[type][i] = INF;
        visit[i] = 0;
    } // dist 초기화

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,X});

    dist[type][X] = 0;

    while (!PQ.empty()) {
        int now = PQ.top().second, cost = PQ.top().first;
        PQ.pop();

        if (visit[now]) continue;
        visit[now] = 1;

        for (pair<int,int> i : edge[type][now]) {
            int nxt = i.first, n_cost = cost + i.second;

            if (dist[type][nxt] > n_cost) {
                dist[type][nxt] = n_cost;
                PQ.push({n_cost,nxt});
            }
        }
    }
}

void Solve() {
    Dijkstra(FOWARD);
    Dijkstra(BACKWARD);
    
    ans = 0;

    for (int i = 1; i <= N; i++) 
        if (ans < dist[FOWARD][i] + dist[BACKWARD][i])
            ans = dist[FOWARD][i] + dist[BACKWARD][i];
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    Solve();
    cout << ans;
}

/*
idea : 역방향 도로를 조지자

edge와 dist 에서 첫 []의 의미
0은 정방향
1은 역방향
*/