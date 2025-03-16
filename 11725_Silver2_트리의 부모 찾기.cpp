#include <bits/stdc++.h>
#define MAXN 100000
#define endl "\n"
using namespace std;

int N;
int parent[MAXN+1];
vector<int> edge[MAXN+1];

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    queue<int> Q;
    Q.push(1);

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        for (int child : edge[now]) {
            if (child == parent[now]) continue;
            Q.push(child);
            parent[child] = now;
        }
    }

    for (int i = 2; i <= N; i++) cout << parent[i] << endl;
}