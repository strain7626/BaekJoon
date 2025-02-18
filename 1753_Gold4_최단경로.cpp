#include <iostream>
#include <queue>
#define endl "\n"
#define INF 2e9
#define MAXV 20000
using namespace std;

int     V, E, K;
vector<pair<int,int>> adj[MAXV+1];
int     dist[MAXV+1];

void Dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,start});
    
    for (int i=1;i<=V;i++) dist[i] = INF;
    dist[start] = 0;

    while (!PQ.empty()) {
        int cost = PQ.top().first, now = PQ.top().second;
        PQ.pop();

        for (pair<int,int> nxt : adj[now]) {
            if (cost + nxt.first < dist[nxt.second]) {
                dist[nxt.second] = cost + nxt.first;
                PQ.push({dist[nxt.second], nxt.second});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> V >> E;
    cin >> K;

    for (int i=0;i<E;i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    Dijkstra(K);

    for (int i=1;i<=V;i++) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}