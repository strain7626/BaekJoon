#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9
#define endl "\n"
using namespace std;

typedef long long ll;

int                     N, E, v1, v2;
vector<pair<int,int>>   edge[801];
ll                      ans;

void Input() {
    cin >> N >> E;
    for (int i=0;i<E;i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }
    cin >> v1 >> v2;
}

int Dijkstra(int s, int e) {
    vector<int> dist(N+1,INF);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,s});

    while(!PQ.empty()) {
        int now = PQ.top().second, cost = PQ.top().first;
        PQ.pop();

        if (dist[now] != cost) continue; // 이거 있으면 살짝 절약 가능

        for (pair<int,int> i : edge[now]) {
            int nxt = i.second, n_cost = i.first + cost;
            if (dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                PQ.push({n_cost, nxt});
            }
        }
    }

    return dist[e];
}

void Solve() {
    ll  a = Dijkstra(1,v1),
        b = Dijkstra(1,v2),
        c = Dijkstra(v1,v2),
        d = Dijkstra(v1,N),
        e = Dijkstra(v2,N);

    ans = min(a+c+e,b+c+d);
    if (ans >= INF) ans = -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    Solve();
    cout << ans;
}