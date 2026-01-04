#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> E;

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    cin >> N >> M; E.resize(N+1);
    
    while (M--) {
        int u, v; cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int ans = 0;
    vector<bool> vis(N+1);
    
    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        vis[i] = 1; ans++;
        queue<int> Q; Q.push(i);

        while (!Q.empty()) {
            int n = Q.front(); Q.pop();

            for (int e : E[n]) {
                if (vis[e]) continue;
                vis[e] = 1; Q.push(e);
            }
        }   
    }

    cout << ans;
}