#include <bits/stdc++.h>
using namespace std;

int n, m, A, B;
vector<pair<int,int>> edge[100001];
int visited[1001],pre[1001];
vector<int> route;

int Dijkstra() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,A});
    visited[A] = 0;

    while(!PQ.empty()) {
        int now = PQ.top().second, cost = PQ.top().first;
        PQ.pop();

        if (now == B) return cost;

        for (pair<int,int> i : edge[now]) {
            int nxt = i.first, n_cost = cost + i.second;

            if (visited[nxt] > n_cost) {
                visited[nxt] = n_cost;
                PQ.push({n_cost, nxt});
                pre[nxt] = now;
            }
        }
    }

    return -1;
}

int GetRoute() {
    route.push_back(B);

    while (route.back() != A)
        route.push_back(pre[route.back()]);
    reverse(route.begin(),route.end());

    return route.size();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t; cin >> u >> v >> t;
        edge[u].push_back({v,t});
    }
    cin >> A >> B;

    for (int i = 1; i <= n; i++) visited[i] = 2e9;
    cout << Dijkstra() << endl;
    cout << GetRoute() << endl;
    for (int i : route) cout << i << " ";
}