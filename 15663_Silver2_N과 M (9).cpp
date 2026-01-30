#include <bits/stdc++.h>

using namespace std;

int N, M, A[8], vis[8];
vector<int> tmp;
set<vector<int>> ans;

void DFS(int cnt) {
    if (!cnt) {
        ans.insert(tmp);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        tmp.push_back(A[i]);
        DFS(cnt-1);
        vis[i] = 0;
        tmp.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    DFS(M);
    for (auto& i : ans) { for (auto& x : i) cout << x << ' '; cout << '\n'; }
}