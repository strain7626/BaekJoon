#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> E[300001];
int V[300001], DP[300001];

int DFS(int now, int parent, int dist) {
    DP[now] = dist;

    V[now] = 1;
    for (pair<int, int> i : E[now]) if (i.first != parent) {
        V[now] += DFS(i.first, now, dist + i.second);
    }

    return 
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        E[u].push_back({v, d}); E[v].push_back({u, d});
    }

    cout << DFS(1, 0, 0) << '\n';
    for (int i = 1; i <= N; i++) cout << DP[i] << ' ';
}