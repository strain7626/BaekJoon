#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9
#define endl "\n"
using namespace std;

typedef long long ll;

int N, M;
vector<tuple<int,int,int>> edge;
ll dist[501];

void Input() {
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b,c; cin >> a >> b >> c;
        edge.push_back(make_tuple(a,b,c));
    }
}

bool BellmanFord() {
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[1] = 0;

    // N-1번 실행
    for (int i = 0; i < N-1; i++) {
        for (tuple<int,int,int> tmp : edge) {
            int u,v,t; tie(u,v,t) = tmp;

            if (dist[u] != INF && dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
            }
        }
    }

    // 음수 사이클 체크
    for (tuple<int,int,int> tmp : edge) {
        int u,v,t; tie(u,v,t) = tmp;

        if (dist[u] != INF && dist[v] > dist[u] + t) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    Input();
    if (BellmanFord()) cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) cout << -1 << endl;
            else cout << dist[i] << endl;
        }
    }
}