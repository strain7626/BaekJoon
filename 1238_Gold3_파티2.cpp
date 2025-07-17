#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, M, X, dist[1001][2];
vector<pair<int,int>> E[1001][2];

void Dijkstra(int T) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({dist[X][T] = 0,X});

    while (!PQ.empty()) {
        int cost = PQ.top().first, now = PQ.top().second;
        PQ.pop();

        for (pair<int,int> i : E[now][T]) {
            int nxt = i.first, n_cost = cost+i.second;

            if (dist[nxt][T] <= n_cost) continue;
            PQ.push({dist[nxt][T] = n_cost, nxt});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int A, B, T; cin >> A >> B >> T;
        E[A][0].push_back({B,T}); E[B][1].push_back({A,T});
    }
    
    for (int i = 1; i <= N; i++) dist[i][0] = dist[i][1] = INF;
    Dijkstra(0); Dijkstra(1);

    int ans = 0;
    for (int i = 1; i <= N; i++) ans = max(ans, dist[i][0] + dist[i][1]);
    cout << ans;
}