#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, DP[1000001][2];
vector<int> E[1000001];

int DFS(int now, int parent, bool isEarly) {
    if (E[now].size() == 1 && parent) return isEarly;
    if (DP[now][isEarly]) return DP[now][isEarly];
    for (int i : E[now]) if (i != parent) 
        DP[now][isEarly] += (isEarly ? min(DFS(i, now, 0), DFS(i, now, 1)) : DFS(i, now, 1));
    return DP[now][isEarly] += isEarly;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        E[u].push_back(v); E[v].push_back(u);
    }

    cout << min(DFS(1, 0, 1), DFS(1, 0, 0));
}