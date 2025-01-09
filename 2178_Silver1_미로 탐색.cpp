#include <iostream>
#include <queue>

using namespace std;

int N, M;
int graph[100][100];
queue<pair<int,int>> myQ;
int dx[] = {0,0,-1,1}, dy[] = {-1,1,0,0};

void Input() {
    cin >> N >> M;
    for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) {
        char c;
        cin >> c;
        graph[n][m] = (c=='0'?0:1);
    }
    myQ.push({0,0});
    graph[0][0] = 0;
}

bool lineout(int x, int y) {
    if (y>=N||y<0 || x>=M||x<0) return true;
    else return false;
}

int BFS(int cnt) {
    int t = myQ.size();
    while (t--) {
        int x = myQ.front().first, y = myQ.front().second;
        myQ.pop();
        if (x == M-1 && y == N-1) return cnt;

        for (int i = 0; i < 4; i++)
            if (!lineout(x+dx[i],y+dy[i]) && graph[y+dy[i]][x+dx[i]] == 1) {
                myQ.push({x+dx[i],y+dy[i]});
                graph[y+dy[i]][x+dx[i]] = 0;
            }
    }
    return BFS(cnt+1);    
}

int main() {
    Input();
    cout << BFS(1);
    
    return 0;
}