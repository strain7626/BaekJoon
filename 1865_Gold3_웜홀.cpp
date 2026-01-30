#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, M, W, dist[501];
vector<tuple<int,int,int>> edge;
 
string BellmanFord() {
    for (int i = 1; i <= N; i++) for (auto& j : edge) {
        int S, E, T; tie(S, E, T) = j;
        if (dist[S]!=INF && dist[S]+T < dist[E]) {
            dist[E] = dist[S]+T;
            if (i == N) return "YES\n";
        }
    }
    return "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int TC; cin >> TC; while (TC--) {
        cin >> N >> M >> W;
        edge.clear();
        for (int i = 1; i <= N; i++) dist[1] = 0;
        for (int i = 0; i < M+W; i++) {
            int S, E, T; cin >> S >> E >> T;
            edge.push_back({S,E,T});
            edge.push_back({E,S,T});
        }
        for (int i = 0; i < M+W; i++) {
            int S, E, T; cin >> S >> E >> T;            
            edge.push_back({S,E,-T});
        }

        cout << BellmanFord();
    }
}