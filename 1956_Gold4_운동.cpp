#include <iostream>
#define INF 1e9
using namespace std;

int V, E,
    dist[401][401],
    ans;

void Input() {
    cin >> V >> E;
    for (int a=1;a<=V;a++) for (int b=1;b<=V;b++) dist[a][b] = INF;
    for (int i=0;i<E;i++) {
        int a,b,c; cin >> a >> b >> c;
        dist[a][b] = c;
    }
}

void FloydWarshall() {
    for (int k = 1; k <= V; k++) {
        for (int a = 1; a <= V; a++) {
            for (int b = 1; b <= V; b++) {
                if (dist[a][b] > dist[a][k]+dist[k][b])
                    dist[a][b] = dist[a][k]+dist[k][b];
            }
        }
    }
}

void Solve() {
    FloydWarshall();

    ans = INF;
    for (int i = 1; i <= V; i++) 
        if (ans > dist[i][i])
            ans = dist[i][i];
    
    if (ans == INF) ans = -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    Solve();
    cout << ans;
}