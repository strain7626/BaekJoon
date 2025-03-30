#include <bits/stdc++.h>
using namespace std;

int m, n;
int uni[200000];
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> PQ;

int uni_find(int now) {
    return (uni[now] == now ? now : uni[now] = uni_find(uni[now]));
}

int Kruskal() {
    int ans = 0;

    while (!PQ.empty()) {
        int cost = PQ.top().first, x = PQ.top().second.first, y = PQ.top().second.second;
        x = uni_find(x); y = uni_find(y);
        PQ.pop();

        if (x == y) continue;

        ans += cost;
        uni[x] = y;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while (1) {
        cin >> m >> n;
        if (m==0 && n==0) break;
        
        int sum = 0;
        for (int i = 0; i < m; i++) uni[i] = i;
        for (int i = 0; i < n; i++) {
            int x, y, z; cin >> x >> y >> z;
            PQ.push({z,{x,y}});
            sum += z;
        }

        cout << sum - Kruskal() << '\n';
    }
}