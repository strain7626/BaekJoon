#include <bits/stdc++.h>

using namespace std;

int N, M, A[10000];
bool vis[10000];

void DFS(vector<int>& ans, int cnt) {
    if (!cnt) {
        for (int& i : ans) cout << i << ' '; 
        cout << '\n'; 
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        
        vis[i] = 1;
        ans.push_back(A[i]);
        DFS(ans, cnt-1);
        vis[i] = 0;
        ans.pop_back();
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    vector<int> tmp;
    DFS(tmp, M);
}