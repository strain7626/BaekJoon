#include <iostream>
#define ll long long
using namespace std;

int N,
    graph[101][101];
ll  result,
    DP[101][101];

void Input() {
    cin >> N;
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) cin >> graph[i][j];
}

ll DFS(int y, int x) {
    if (y == N && x == N) return 1;
    if (y > N || x > N || graph[y][x] == 0) return 0;
    if (DP[y][x]) return DP[y][x];
    DP[y][x] = DFS(y+graph[y][x],x) + DFS(y,x+graph[y][x]);
    return DP[y][x];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Input();
    cout << DFS(1,1);
}