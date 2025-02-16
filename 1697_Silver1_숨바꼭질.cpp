#include <iostream>
#include <queue>
#define INF 100000
using namespace std;

int N, K;
int visited[INF+1];
int ans;

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

        if (now+1 <= INF && !visited[now+1]) {
            visited[now+1] = visited[now]+1;
            Q.push(now+1);
        }
        if (now-1 >= 0 && !visited[now-1]) {
            visited[now-1] = visited[now]+1;
            Q.push(now-1);
        }
        if (now*2 <= INF && !visited[now*2]) {
            visited[now*2] = visited[now]+1;
            Q.push(now*2);
        }
    }
}

int main() {
    cin >> N >> K;
    BFS();
    cout << ans;
}