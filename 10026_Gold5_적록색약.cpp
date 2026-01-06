#include <bits/stdc++.h>

using namespace std;

struct pos {int y,x;};

int N, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
vector<string> graph;

int BFS() {
    vector<vector<bool>> vis(N, vector<bool>(N,0));
    queue<pos> Q;

    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (vis[i][j]) continue;

        Q.push({i,j});
        char T = graph[i][j];
        ans++;

        while (!Q.empty()) {
            int y = Q.front().y, x = Q.front().x; Q.pop();
            for (int k = 0; k < 4; k++) {
                int ny = y+dy[k], nx = x+dx[k];
                if (ny<0||ny>=N||nx<0||nx>=N) continue;
                if (graph[ny][nx] != T) continue;
                if (vis[ny][nx]) continue;

                vis[ny][nx] = 1;
                Q.push({ny,nx});
            }
        }
    }
    
    return ans;
}


int main() {
    cin.tie(0);ios::sync_with_stdio(0);

    cin >> N; graph.resize(N);
    for (auto& S : graph) cin >> S; 

    cout << BFS() << ' ';
    for (auto& S : graph) for (auto& c : S) if (c == 'R') c = 'G';
    cout << BFS();
}