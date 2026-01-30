#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int N, K, vis[MAX+1], cnt[MAX+1];

void BFS() {
    vis[N] = 1; cnt[N] = 1;
    queue<int> Q; Q.push(N);

    while (!Q.empty()) {
        int now = Q.front(); Q.pop();
        if (vis[K] && vis[now] == vis[K]) break;

        for (int nxt : { now-1, now+1, now*2 }) {

            if (nxt<0||nxt>MAX) continue;
            if (vis[nxt]) {
                if (vis[nxt] == vis[now]+1) cnt[nxt] += cnt[now];
                continue;
            }

            vis[nxt] = vis[now]+1;
            cnt[nxt] = cnt[now];
            Q.push(nxt);
        }
    }

    cout << vis[K]-1 << '\n' << cnt[K];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;
    BFS();
}