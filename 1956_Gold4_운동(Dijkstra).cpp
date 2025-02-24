#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int V, E;
vector<pair<int,int>> edge[401];
int ans;

void Input() {
    cin >> V >> E;
    for (int i=0;i<E;i++) {
        int a,b,c; cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }
}

int Dijkstra(int start) {
    vector<int> dist(V+1,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;

    for (pair<int,int> i : edge[start]) {
        dist[i.first] = i.second;
        PQ.push({i.second, i.first});
    }

    while (!PQ.empty()) {
        int now = PQ.top().second, cost = PQ.top().first;
        PQ.pop();

        if (now == start) return cost;

        for (pair<int,int> i : edge[now]) {
            int nxt = i.first, n_cost = cost + i.second;
            if (dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                PQ.push({n_cost, nxt});
            }
        }
    }

    return INF;
}

void Solve() {
    ans = INF;
    for (int i = 1; i <= V; i++) 
        ans = min(ans, Dijkstra(i));
    if (ans == INF) ans = -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    Solve();
    cout << ans;
}