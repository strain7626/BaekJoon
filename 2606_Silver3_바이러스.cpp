#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> Edges[101];
bool visited[101];
int ans = 0;

void BFS() {
    queue<int> Q;
    Q.push(1);
    visited[1] = 1;
    // ans++; 1번 컴퓨터는 카운트 X

    while (!Q.empty()) {
        for (int i : Edges[Q.front()]) if (!visited[i]) {
            Q.push(i);
            visited[i] = 1;
            ans++;
        }
        Q.pop();
    }
}

int main() {
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int u, v; cin >> u >> v;
        Edges[u].push_back(v);
        Edges[v].push_back(u);
    }

    BFS();

    cout << ans;
}