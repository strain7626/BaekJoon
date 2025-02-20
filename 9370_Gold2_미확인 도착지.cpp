#include <iostream>
#include <queue>
#include <algorithm>
#define INF 1e9
#define endl "\n"
using namespace std;

int n, m, t,
    s, g, h;
vector<pair<int,int>> edge[2001];
vector<int> dest;
vector<int> ans;

void Input() {
    cin >> n >> m >> t;
    cin >> s >> g >> h;

    // 리셋
    for (int i=1;i<=n;i++) edge[i].clear();
    dest = vector<int>(t,0);
    ans.clear();

    for (int i=0;i<m;i++) {
        int a, b, d; cin >> a >> b >> d;
        edge[a].push_back({d,b});
        edge[b].push_back({d,a});
    }
    for (int i=0;i<t;i++) cin >> dest[i];
}

int Dijkstra(int st, int ed) {
    vector<int> dist(n+1,INF);
    dist[st] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    PQ.push({0,st});

    while(!PQ.empty()) {
        int now = PQ.top().second, cost = PQ.top().first;
        PQ.pop();

        for (pair<int,int> i : edge[now]) {
            int nxt = i.second, n_cost = cost + i.first;
            if (dist[nxt] > n_cost) {
                dist[nxt] = n_cost;
                PQ.push({n_cost, nxt});
            }
        }
    }

    return dist[ed];
}

void Solve() {
    int gh; // g와 h 사이 거리
    for (pair<int,int> i : edge[g]) if (i.second == h) {
        gh = i.first;
        break;
    }

    for (int e : dest) {
        int minDist = Dijkstra(s,e); // 원래 최소거리
        if (minDist == INF) continue;
        
        if ( // g와 h 사이를 지날때 최소거리와 같다면
            minDist == Dijkstra(s,g) + gh + Dijkstra(h,e) ||
            minDist == Dijkstra(s,h) + gh + Dijkstra(g,e)
        ) {
            ans.push_back(e);
        }
    }
    
    sort(ans.begin(), ans.end());
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        Input();
        Solve();
        for (int i : ans) cout << i << " ";
        cout << endl;
    }
}