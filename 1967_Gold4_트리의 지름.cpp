#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> edge[10001];
int ans = 0;

int DFS(int now) {
    int M = 0;

    for (pair<int,int> i : edge[now]) {
        int tmp = DFS(i.first) + i.second;
        ans = max(ans, M + tmp);
        M = max(M, tmp);
    }

    return M;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }

    DFS(1);

    cout << ans;
}