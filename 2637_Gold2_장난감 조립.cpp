#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int N,M,DP[101][101];
bool vis[101];
vector<pii> A[101];

void DFS(int X) {
    if (vis[X]) return;
    vis[X]=1;

    if (A[X].empty()) DP[X][X]=1;
    for (auto [Y,K]:A[X]) {
        DFS(Y);
        for (int i=0;i<N;i++) DP[X][i]+=DP[Y][i]*K;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N >> M;
    while (M--) {
        int X,Y,K;cin>>X>>Y>>K;
        A[X].push_back({Y,K});
    }
    
    DFS(N);

    for (int i=1;i<N;i++) if (DP[N][i]) cout << i << ' ' << DP[N][i] << '\n';
}