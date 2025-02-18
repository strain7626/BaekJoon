#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;
int visited[20001]; // 0: 탐색 안 함, 1: 타입1, 2: 타입2
vector<int> Edge[20001];
string ans;

void Input() {
    cin >> V >> E;
    for (int i=1;i<=V;i++) {
        Edge[i].clear();
        visited[i] = 0;
    }
    for (int i=0;i<E;i++) {
        int u, v; cin >> u >> v;
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }
}

void BFS(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start] = 1;

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for (int nxt : Edge[now]) {
            if (visited[nxt] == visited[now]) {
                ans = "NO";
                return;
            }

            if (visited[nxt] == 0) {
                Q.push(nxt);
                visited[nxt] = (visited[now]==1 ? 2 : 1);
            }
        }
    }

    ans = "YES";
}

int main() {
    int K; cin >> K;
    while (K--) {
        Input();
        for (int i = 1; i <= V; i++) if (visited[i] == 0) {
            BFS(i);
            if (ans == "NO") break;
        }
        cout << ans << endl;
    }
}