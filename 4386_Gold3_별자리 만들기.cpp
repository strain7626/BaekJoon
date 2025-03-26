#include <bits/stdc++.h>
using namespace std;

int n;
int uni[100];
vector<pair<double,double>> pos;
vector<pair<int,int>> edge;
priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> PQ;
double ans;

int uni_find(int now) {
    if (uni[now] == now) return now;
    return uni[now] = uni_find(uni[now]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        for (int j = 0; j < pos.size(); j++) {
            double dist = sqrt((pos[j].first-x)*(pos[j].first-x) + (pos[j].second-y)*(pos[j].second-y));
            PQ.push({dist,edge.size()});
            edge.push_back({i,j});
        }
        pos.push_back({x,y});
        uni[i] = i;
    }

    ans = 0;
    while (!PQ.empty()) {
        double dist = PQ.top().first;
        int edgeNum = PQ.top().second;
        PQ.pop();

        int u = edge[edgeNum].first, v = edge[edgeNum].second;
        u = uni_find(u); v = uni_find(v);

        if (u == v) continue;

        uni[u] = v;
        ans += dist;
    }

    cout << ans;
}