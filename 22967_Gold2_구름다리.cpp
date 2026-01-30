#include <bits/stdc++.h>

using namespace std;

int N;
bool edge[301][301];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    if (N <= 4) {
        cout << (N == 2 ? 0 : N == 3 ? 1 : 3) << "\n1\n";
        for (int i = 1; i <= N; i++) for (int j = i+1; j <= N; j++)
            if (!edge[i][j]) cout << i << ' ' << j << '\n';
    } else {
        vector<pair<int,int>> ans;
        for (int i = 2; i <= N; i++) if (!edge[1][i])
            ans.push_back({1, i});
        cout << ans.size() << "\n2\n";
        for (auto& [a, b] : ans) cout << a << ' ' << b << '\n';
    }
}