#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int graph[50][50];

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void Reset() {
    for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++)
        graph[i][j] = 0;
}

void Input() {
    Reset();

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        graph[y][x] = 1;
    }
}

bool lineout(int y, int x) {
    if (x>=M||x<0||y>=N||y<0) return true;
    return false;
}

void BFS(pair<int,int> start_point) {
    queue<pair<int,int>> myQ;
    myQ.push(start_point);

    while (!myQ.empty()) {
        int x = myQ.front().second, y = myQ.front().first;
        graph[y][x] = 0;
        myQ.pop();

        for (int i = 0; i < 4; i++) {
            int fx = x+dx[i], fy = y+dy[i];
            if (!lineout(fy,fx) && graph[fy][fx] == 1) {
                graph[fy][fx] = 0;
                myQ.push({fy,fx});
            }
        }
    }
}

int Count() {
    int cnt = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (graph[i][j] == 1) {
            BFS({i,j});
            cnt++;
        }   
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Input();
        cout << Count() << endl;
    }
}