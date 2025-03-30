#include <bits/stdc++.h>
#define INF 2e9
using namespace std;

int N, M;
int DP[1001];
int dist[1001];
vector<pair<int,int>> edge[1001];

void Dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,2});

    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[2] = 0;

    while (!PQ.empty()) {
        int cost = PQ.top().first, now = PQ.top().second;
        PQ.pop();

        for (pair<int,int> i : edge[now]) {
            int nxt = i.first, n_cost = cost+i.second;

            if (dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                PQ.push({n_cost,nxt});
            }
        }
    }
}

int DFS(int now, int parent) {
    if (DP[now] || now == 2) return DP[now];

    for (pair<int,int> i : edge[now]) {
        if (dist[now] <= dist[i.first]) continue;
        DP[now] += DFS(i.first, now);
    }

    return DP[now];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C; cin >> A >> B >> C;
        edge[A].push_back({B,C});
        edge[B].push_back({A,C});
    }
    
    Dijkstra();
    DP[2] = 1;
    cout << DFS(1,0);
}