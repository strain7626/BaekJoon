#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int V, E, K, dist[20001];
vector<pair<int,int>> edge[20001];

void Dijkstra(int S) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({dist[S] = 0,S});

    while (!PQ.empty()) {
        int cost = PQ.top().first, now = PQ.top().second; 
        PQ.pop();

        for (pair<int,int> i : edge[now]) {
            int nxt = i.first, n_cost = cost+i.second;
            if (dist[nxt] <= n_cost) continue;
            PQ.push({dist[nxt] = n_cost, nxt});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back({v,w});
    }

    for (int i = 1; i <= V; i++) dist[i] = INF;
    Dijkstra(K);

    for (int i = 1; i <= V; i++) 
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
}