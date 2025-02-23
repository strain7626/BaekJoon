#include <iostream>
#define endl "\n"
#define INF 1e9
using namespace std;

int n, m;
long long dist[101][101];

void Input() {
    cin >> n;
    cin >> m;

    // dist 값 초기화
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dist[i][j] = INF;
    for (int i=1;i<=n;i++) dist[i][i] = 0;

    for (int i=0;i<m;i++) {
        int a,b,c; cin >> a >> b >> c;
        if (dist[a][b] > c)
            dist[a][b] = c;
    }
}

void FloydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                if (dist[a][b] > dist[a][k] + dist[k][b])
                    dist[a][b] = dist[a][k] + dist[k][b];
            }
        }    
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    FloydWarshall();
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (dist[a][b] == INF) cout << 0 << " ";
            else cout << dist[a][b] << " ";
        }
        cout << endl;
    }
}