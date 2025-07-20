#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> E[300001];
int V[300001];
long DP[300001];

void DFS(int now, int parent) {
    V[now] = 1;
    for (pair<int, int> i : E[now]) if (i.first != parent) {
        DFS(i.first, now);
        DP[now] += i.second*V[i.first] + DP[i.first]; 
        V[now] += V[i.first];
    }
}

void DFS2(int now, int parent, int dist, int I) {
    if (now != 1) DP[now] = DP[parent] + (I - V[now])*dist;
    for (pair<int, int> i : E[now]) if (i.first != parent)
        DFS2(i.first, now, i.second, I+V[now]-V[i.first]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v, d; cin >> u >> v >> d;
        E[u].push_back({v, d}); E[v].push_back({u, d});
    }
    
    DFS(1, 0);
    DFS2(1,0,0,0);
    for (int i = 1; i <= N; i++) cout << DP[i] << '\n';
}