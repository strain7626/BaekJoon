#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

typedef struct _pos {
    int y,x;
    bool operator==(_pos &cmp) {
        return (y == cmp.y && x == cmp.x);
    }
} pos;

int l,
    visited[300][300],
    dy[] = {2,1,-1,-2,-2,-1,1,2}, dx[] = {1,2,2,1,-1,-2,-2,-1};
pos start, goal;
int ans;

void Input() {
    cin >> l;
    cin >> start.y >> start.x;
    cin >> goal.y >> goal.x;

    for (int i=0;i<l;i++) for (int j=0;j<l;j++) visited[i][j] = -1;
}

bool lineout(int y, int x) {
    if (y<0||y>=l||x<0||x>=l) return true;
    return false;
}

void BFS() {
    queue<pos> Q;
    Q.push(start);
    visited[start.y][start.x] = 0;

    while(!Q.empty()) {
        int y = Q.front().y, x = Q.front().x;
        Q.pop();

        if (pos{y,x} == goal) {
            ans = visited[y][x];
            return;
        }

        for (int i = 0; i < 8; i++) {
            int fy = y+dy[i], fx = x+dx[i];
            if (!lineout(fy,fx) && visited[fy][fx] == -1) {
                Q.push({fy,fx});
                visited[fy][fx] = visited[y][x]+1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        Input();
        BFS();
        cout << ans << endl;
    }
}