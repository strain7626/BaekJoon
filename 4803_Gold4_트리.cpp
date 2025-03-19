#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, m;
vector<int> edge[501];
bool vis[501];
int ans;

void Input() {
    cin >> n >> m;
    if (n == 0 && m == 0) exit(0);

    for (int i = 1; i <= n; i++) {
        edge[i].clear();
        vis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

bool DFS(int now, int parent) {
    if (vis[now]) return 0;
    vis[now] = 1;
    for (int i : edge[now]) if (i != parent) {
        if (!DFS(i, now)) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int c = 0;
    while (1) {
        c++;
        Input();

        ans = 0;
        for (int i = 1; i <= n; i++) 
            ans += (!vis[i] && DFS(i, 0));

        cout << "Case " << c << ": ";
        if (ans == 0) cout << "No trees.";
        else if (ans == 1) cout << "There is one tree.";
        else cout << "A forest of " << ans << " trees.";
        cout << endl;
    }
}