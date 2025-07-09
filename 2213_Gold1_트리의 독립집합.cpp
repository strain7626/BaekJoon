#include <iostream>
#include <vector>
using namespace std;

int n, w[10001];
vector<pair<int,int>> E[10001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        E[u].push_back({v,w[i]}); E[v].push_back({u,w[i]});
    }

    

    

    
}