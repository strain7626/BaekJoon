#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n";
using namespace std;

typedef struct _pos {
    int y;
    int x;
} pos;

int     N,
        dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1};
char    graph[25][25];
bool    visited[25][25];
vector<int> ans;

bool canGo(pos P) {
    int y = P.y, x = P.x;
    if (y<0||y>=N||x<0||x>=N) return false;
    if (visited[y][x]) return false;
    if (graph[y][x] == '0') return false;

    return true;
}

void BFS(pos P) {
    queue<pos> Q;
    Q.push(P);
    visited[P.y][P.x] = 1;
    int cnt = 1;

    while (!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fy = y+dy[i], fx = x+dx[i];

            if (canGo({fy,fx})) {
                Q.push({fy,fx});
                visited[fy][fx] = 1;
                cnt++;
            }
        }
    }

    ans.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> graph[i][j];
    for (int i=0;i<N;i++) for (int j=0;j<N;j++)
        if (canGo({i,j})) BFS({i,j});

    sort(ans.begin(), ans.end());
        
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
}