#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int N, M;
int uni[1001];
vector<pair<ll,ll>> pos;
vector<pair<int,int>> edge;
priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<>> PQ;
ld ans;

int uni_find(int now) {
    if(uni[now] == now) return now;
    return uni[now] = uni_find(uni[now]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    pos.push_back({0,0});
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        uni[i] = i;
        ll X, Y; cin >> X >> Y;

        for (int j = 1; j < pos.size(); j++) {
            ld dist = sqrt((pos[j].first-X)*(pos[j].first-X) + (pos[j].second-Y)*(pos[j].second-Y));
            PQ.push({dist,edge.size()});
            edge.push_back({i,j});
        }

        pos.push_back({X,Y});
    }
    for (int i = 0; i < M; i++) {
        int U, V; cin >> U >> V;
        U = uni_find(U); V = uni_find(V);
        uni[U] = V;
    }

    ans = 0;

    while (!PQ.empty()) {
        ld dist = PQ.top().first;
        int edgeNum = PQ.top().second;
        PQ.pop();

        int U = edge[edgeNum].first, V = edge[edgeNum].second;
        U = uni_find(U); V = uni_find(V);

        if (U == V) continue;

        ans += dist;
        uni[U] = V;
    }

    ans *= 100;
    ll tmp = round(ans);
    ll part1 = tmp/100;
    ll part2 = tmp%100;

    cout << part1 << '.';
    cout << part2/10;
    cout << part2%10;
}