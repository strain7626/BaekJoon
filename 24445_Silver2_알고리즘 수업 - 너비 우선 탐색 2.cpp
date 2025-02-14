#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl "\n"
#define INF 100000
using namespace std;

int N, M, R;
vector<int> Edges[INF+1];
int visited[INF+1];
int cnt = 1;

void BFS(int now) {
    queue<int> Q;
    Q.push(now);

    while (!Q.empty()) {
        visited[Q.front()] = cnt++;
        sort(Edges[Q.front()].begin(), Edges[Q.front()].end(), greater<>());
        for (int i : Edges[Q.front()]) if (!visited[i]) { 
            visited[i] = 1; // 임시
            Q.push(i);
        }
        Q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M >> R;
    for (int i=0;i<M;i++) {
        int u, v; cin >> u >> v;
        
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    BFS(R);

    for (int i = 1; i <= N; i++) cout << visited[i] << endl;
}