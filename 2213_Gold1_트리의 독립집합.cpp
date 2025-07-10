#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,          w[10001], DP[10001][2];
vector<int>     E[10001];
set<int>        S[10001][2];

int DFS(int now, int parent, bool isS) {
    if (DP[now][isS]) return DP[now][isS];
    
    for (int i : E[now]) if (i != parent) {
        DP[now][isS] += (isS ? DFS(i, now, 0) : max(DFS(i, now, 0), DFS(i, now, 1)));
        if (!isS && (DFS(i, now, 0) < DFS(i, now, 1))) S[now][isS].insert(S[i][1].begin(), S[i][1].end());
        else S[now][isS].insert(S[i][0].begin(), S[i][0].end());
    }

    if (isS) {
        DP[now][isS] += w[now];
        S[now][isS].insert(now);
    }

    return DP[now][isS];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        E[u].push_back(v); E[v].push_back(u);
    } 

    E[0].push_back(1);
    cout << DFS(0, 0, 0) << '\n';
    for (int i : S[0][0]) cout << i << ' ';
}