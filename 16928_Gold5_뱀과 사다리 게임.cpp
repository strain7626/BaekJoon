#include <iostream>
#include <deque>
#define endl "\n"
using namespace std;

int N, M;
//주사위 범위 고려 0은 비움
int ladder[106], snake[106];
int visited[106];

void Input() {
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        int x, y; cin >> x >> y;
        ladder[x] = y;
    }
    for (int i=0;i<M;i++) {
        int u, v; cin >> u >> v;
        snake[u] = v;
    }
}

void Solve() { 
    deque<int> dq;
    dq.push_back(1);

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        if (cur == 100) {
            cout << visited[100] << endl;
            return;
        }else if (cur > 100) continue;

        if (ladder[cur]) {
            dq.push_front(ladder[cur]);
            visited[ladder[cur]] = visited[cur];
            continue;
        }

        if (snake[cur]) {
            dq.push_front(snake[cur]);
            visited[snake[cur]] = visited[cur];
            continue;
        }

        for (int i = 1; i <= 6; i++) {
            int nxt = cur+i;

            if (!visited[nxt]) {
                dq.push_back(nxt);
                visited[nxt] = visited[cur]+1;
            }
        }
    }
}                               

int main() {
    Input();
    Solve();
}