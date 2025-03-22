#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int N;
int A[MAXN+1];
int DP[MAXN+1];
vector<int> edge[MAXN+1];

int DFS(int now, int parent) {
    if (DP[now]) return DP[now];

    int ans1 = 0;
    // 우수마을 선정 X
    for (int i : edge[now]) if (i != parent) {
        ans1 += DFS(i, now);
    }

    int ans2 = A[now];
    // 우수마을 선정 O
    for (int i : edge[now]) if (i != parent) {
        for (int j : edge[i]) if (j != now) {
            ans2 += DFS(j, i);
        }
    }

    return DP[now] = max(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    cout << DFS(1, 0);
}