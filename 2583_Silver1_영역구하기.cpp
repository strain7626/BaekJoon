#include <bits/stdc++.h>
using namespace std;

int M, N, K;
bool graph[101][101];
vector<int> ans;

int BFS(pair<int,int> start) {
    int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

    graph[start.first][start.second] = 1;
    int result = 1;
    
    queue<pair<int,int>> Q;
    Q.push(start);

    while (!Q.empty()) {
        int y = Q.front().first, x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (fy<0||fy>=M||fx<0||fx>=N) continue;
            if (graph[fy][fx]) continue;

            graph[fy][fx] = 1;
            Q.push({fy,fx});
            result++;
        }
    }

    return result;
}

int main() {
    cin >> M >> N >> K;

    while (K--) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        for (int x = a; x < c; x++) for (int y = b; y < d; y++)
            graph[y][x] = 1;
    }

    for (int y = 0; y < M; y++) for (int x = 0; x < N; x++) 
        if (!graph[y][x]) ans.push_back(BFS({y,x}));

    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}