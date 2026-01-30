#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, r, t[100], cnt[100], dist[100][100];

int Floyd() {
    int ans = 0;

    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
        cnt[i] += (dist[i][j] <= m ? t[j] : 0);
    for (int i = 0; i < n; i++)   
        ans = max(ans, cnt[i]);

    return ans;
}
    
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = INF;
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        a--; b--;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    cout << Floyd();
}