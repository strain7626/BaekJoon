#include <bits/stdc++.h>
#define MAXV 100000
using namespace std;

int V;
vector<pair<int,int>> edge[MAXV+1];
int ans;

void Input() {
    cin >> V;
    for (int i = 0; i < V; i++) {
        int u; cin >> u;
        while (1) {
            int v; cin >> v;
            if (v == -1) break;
            int d; cin >> d;
            edge[u].push_back({v,d});
        }
    }
}

int DFS(int now, int parent) {
    int M1 = 0, M2 = 0;
    
    for (pair<int,int> i : edge[now]) {
        if (i.first == parent) continue;

        int tmp = DFS(i.first, now) + i.second;
        if (tmp > M1) {M2 = M1; M1 = tmp;}
        else if (tmp > M2) M2 = tmp;
    }

    ans = max(ans, M1+M2);

    return M1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    Input();

    ans = 0;
    DFS(V,0);

    cout << ans;
}