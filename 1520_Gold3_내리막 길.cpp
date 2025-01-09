#include <iostream>
#include <queue>

using namespace std;

int M,N,graph[500][500];
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void Input() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
        cin >> graph[i][j];
}
int Solve() {
    int H = 0;
    queue<pair<int,int>> myQ;
    myQ.push({0,0});

    return H;
}

int main() {
    Input();
    cout << Solve();
}

9 8 7 6 5
8 7 6 5 4
7 6 5 4 3
6 5 4 3 2
5 4 3 2 1

1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0  0
0 0 0 0 0