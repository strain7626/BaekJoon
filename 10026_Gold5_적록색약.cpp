#include <bits/stdc++.h>

using namespace std;

int N, dy[] = {-1,1,0,0}, dx[] = {0,0,-1,1}, cnt = 0; 
vector<string> A; vector<vector<int>> vis;

void check(int _y, int _x) {
    cnt++;
    vis[_y][_x] = 1;
    char C = A[_y][_x];
    queue<pair<int,int>> Q; Q.push({_y,_x});
    cout << 'h';
    while (!Q.empty()) {
        cout << cnt;
        int y = Q.front().first, x = Q.front().second; Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            
            if (ny<0||ny>=N||nx<0||nx>=N) continue;
            if (vis[ny][nx]) continue;
            if (A[ny][nx] != C) continue; 

            vis[ny][nx] = 1;
            Q.push({ny,nx});
        }
    }
}

int main() {
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

    cin >> N; A.resize(N); for (auto& x : vis) x.resize(N); A.resize(N);
    for (auto& a : A) cin >> a;

    cout << 'h';
    for (int y; y < N; y++) for (int x; x < N; x++) {
        if (!vis[y][x]) check(y,x);
        if (A[y][x] == 'G') A[y][x] = 'R';
        cout << cnt;
    }
    for (auto& x : vis) fill(x.begin(), x.end(), 0);
    cout << cnt << ' '; cnt = 0;

    for (int y; y < N; y++) for (int x; x < N; x++) check(y,x);
    cout << cnt;
}