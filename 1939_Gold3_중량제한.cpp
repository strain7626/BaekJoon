#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, M, s, e, dist[100001];
vector<pair<int,int>> E[100001];

int Dijkstra() {
    priority_queue<pair<int,int>> PQ;
    PQ.push({INF, s});

    while (!PQ.empty()) {
        int cost = PQ.top().first, now = PQ.top().second;
        PQ.pop();

        if (now == e) return dist[e];
        for (pair<int,int> i : E[now]) {
            int nxt = i.first, n_cost = min(i.second, cost);

            if (dist[nxt] >= n_cost) continue;
            PQ.push({dist[nxt] = n_cost, nxt});
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C; cin >> A >> B >> C;
        E[A].push_back({B,C});E[B].push_back({A,C});
    }
    cin >> s >> e;

    for (int i = 1; i <= M; i++) dist[i] = 0;
    cout << Dijkstra();
}