#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define INF 100000
using namespace std;

int N, M, R;
vector<int> Edges[INF+1];
int visited[INF+1];
int cnt = 1;

bool compare(int a, int b) { return a > b; }

void DFS(int now) {
    visited[now] = cnt++;
    
    sort(Edges[now].begin(), Edges[now].end(), compare);
    for (int i : Edges[now]) if (!visited[i]) DFS(i);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> M >> R;
    for (int i=0;i<M;i++) {
        int u, v; cin >> u >> v;
        
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    DFS(R);

    for (int i = 1; i <= N; i++) cout << visited[i] << endl;
}