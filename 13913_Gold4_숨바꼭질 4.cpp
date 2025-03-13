#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;

int N, K;
int pre[MAXN], visited[MAXN];
int ans;
vector<int> route;

void BFS() {
    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();

        if (now == K) {
            ans = visited[now];
            break;
        }

        if (now+1 <= MAXN && visited[now+1] == -1) {
            Q.push(now+1);
            visited[now+1] = visited[now]+1;
            pre[now+1] = now;
        }
        if (now-1 >= 0 && visited[now-1] == -1) {
            Q.push(now-1);
            visited[now-1] = visited[now]+1;
            pre[now-1] = now;
        }
        if (now*2 <= MAXN && visited[now*2] == -1) {
            Q.push(now*2);
            visited[now*2] = visited[now]+1;
            pre[now*2] = now;
        }
    }
}

void getRoute() {
    int cur = K;
    while (cur != N) {
        route.push_back(cur);
        cur = pre[cur];
    }
    route.push_back(N);
    reverse(route.begin(), route.end());
}

int main() {
    cin >> N >> K;

    for (int &i : visited) i = -1;
    visited[N] = 0;

    BFS();
    cout << ans << endl;
    
    getRoute();
    for (int i : route) cout << i << " ";
}