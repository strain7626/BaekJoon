#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

int N, W;
vector<pair<int,int>> point; // i번째 사건의 좌표, i == 0 일때 dist 특수계산
int DP[1001][1001]; // 경찰차1이 i번째 사건에서 끝나고 경찰차2가 j번째 사건에서 끝났을 때의 거리합의 최소
pair<int,int> pre[1001][1001]; // DP[i][j] 와 연계, 전 단계의 사건 진행

// 결과 출력용
int ans;
pair<int,int> start;
stack<int> route;

int dist(int p1, int p2) {
    if (p1 == 0) return point[p2].first-1 + point[p2].second-1;
    if (p2 == 0) return N-point[p1].first + N-point[p1].second;
    return abs(point[p1].first-point[p2].first) + abs(point[p1].second-point[p2].second);
}

void getRoute() {
    int cnt = W;
    while(cnt--) {
        if (start.first == cnt+1) route.push(1);
        else route.push(2);
        start = pre[start.first][start.second];        
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N >> W;
    point.push_back({0,0});
    for (int i = 0; i < W; i++) {
        int a, b; cin >> a >> b;
        point.push_back({a,b});
    }

    DP[0][0] = 0;
    DP[1][0] = dist(0,1);
    DP[0][1] = dist(1,0);
    for (int now = 2; now <= W; now++) {
        // 경찰차1 이동
        for (int i = 0; i < now-1; i++) {
            DP[now][i] = DP[now-1][i] + dist(now-1, now);
            pre[now][i] = {now-1,i};
        }
        DP[now][now-1] = 2e9;
        for (int i = 0; i < now-1; i++) {
            int tmp =  DP[i][now-1] + dist(i, now);
            if (DP[now][now-1] > tmp) {
                DP[now][now-1] = tmp;
                pre[now][now-1] = {i,now-1};
            }
        }
        // 경찰차2 이동
        for (int i = 0; i < now-1; i++) {
            DP[i][now] = DP[i][now-1] + dist(now, now-1);
            pre[i][now] = {i,now-1};
        }
        DP[now-1][now] = 2e9;
        for (int i = 0; i < now-1; i++) {
            int tmp = DP[now-1][i] + dist(now, i);
            if (DP[now-1][now] > tmp) {
                DP[now-1][now] = tmp;
                pre[now-1][now] = {now-1,i};
            } 
        }
    }

    ans = 2e9;
    for (int i = 0; i < W; i++) {
        if (ans > DP[i][W]) {
            ans = DP[i][W];
            start = {i,W};
        }
        if (ans > DP[W][i]) {
            ans = DP[W][i];
            start = {W,i};
        }
    }
    getRoute();

    cout << ans << endl;
    while (!route.empty()) {
        cout << route.top() << endl;
        route.pop();
    }
}