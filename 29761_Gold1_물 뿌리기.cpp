#include <iostream>
#include <queue>
using namespace std;

typedef struct { int y, x; } pos;

int N, X, graph[2000][2000], state[2000][2000];
int dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};

struct cmp {
    bool operator() (pos A, pos B) {
        if (graph[A.y][A.x] == graph[B.y][B.x]) return state[A.y][A.x] < state[B.y][B.x]; 
        return graph[A.y][A.x] < graph[B.y][B.x];
    }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    // 입력
    pos S;
    cin >> N >> X >> S.y >> S.x;
    for (int y = 0; y < N; y++) for (int x = 0; x < N; x++)
        cin >> graph[y][x];

    // BFS
    int cnt = 1;

    state[--S.y][--S.x] = X;
    priority_queue<pos, vector<pos>, cmp> Q; Q.push(S);
    while (!Q.empty()) {
        int y = Q.top().y, x = Q.top().x;
        Q.pop();
        if (state[y][x] == 1) continue;

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (fy>=N||fy<0||fx>=N||fx<0) continue; 
            if (graph[fy][fx] == graph[y][x] && state[fy][fx] < state[y][x]-1) {
                if (!state[fy][fx]) cnt++;       
                state[fy][fx] = state[y][x]-1;
                Q.push({fy,fx});
            }
            if (graph[fy][fx] < graph[y][x] && state[fy][fx] < X) {
                if (!state[fy][fx]) cnt++;
                state[fy][fx] = X;
                Q.push({fy,fx});
            }
        }
    }

    cout << cnt;
}