#include <bits/stdc++.h>
using namespace std;

int V, E;
pair<int,int> edge[100000];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
int uni[10001];
int ans;

int uni_find(int now) {
    if (uni[now] == now) return now;
    return uni[now] = uni_find(uni[now]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> V >> E;
    for (int i = 1; i <= V; i++) uni[i] = i;
    for (int i = 0; i < E; i++) {
        int A, B, C; cin >> A >> B >> C;
        edge[i] = {A,B};
        PQ.push({C,i});
    }

    int ans = 0;
    while (!PQ.empty()) {
        int cost = PQ.top().first, idx = PQ.top().second;
        PQ.pop();

        int A = uni_find(uni[edge[idx].first]), B = uni_find(uni[edge[idx].second]);
        if (A == B) continue;

        uni[A] = B;
        ans += cost;
    }

    cout << ans;
}