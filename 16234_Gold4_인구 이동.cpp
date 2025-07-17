#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R, A[50][50];
bool vis[50][50];
int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

bool BFS(pair<int,int> S) {
    queue<pair<int,int>> Q; Q.push(S);
    vis[S.first][S.second] = 1;

    vector<pair<int,int>> U; U.push_back(S);
    int sum = A[S.first][S.second], cnt = 1;

    while (!Q.empty()) {
        int r = Q.front().first, c = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int fr = r+dr[i], fc = c+dc[i];

            if (fr<0||fr>=N||fc<0||fc>=N) continue;
            if (vis[fr][fc]) continue;
            int tmp = abs(A[fr][fc]-A[r][c]);
            if (tmp < L || tmp > R) continue;

            Q.push({fr,fc});
            U.push_back({fr,fc});
            vis[fr][fc] = 1;
            sum += A[fr][fc];
            cnt++;
        }
    }

    if (U.size() == 1) return 0;
    for (pair<int,int> u : U) A[u.first][u.second] = (sum/cnt);

    return 1;
}

bool Solve() {
    bool flag = false;

    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) 
        vis[r][c] = 0;
    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) 
        if (!vis[r][c]) flag += BFS({r,c});

    return flag;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> L >> R;
    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) 
        cin >> A[r][c];

    int ans = 0;
    while (Solve()) ans++;
    cout << ans;
}