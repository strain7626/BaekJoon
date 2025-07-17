#include <iostream>
using namespace std;

int N, S, M, V[1001];
bool DP[51][1001];

int DFS(int i, int P) {
    if (P < 0 || P > M || DP[i][P]) return -1;
    DP[i][P] = 1;
    if (i++ == N) return P;
    return max(DFS(i,P+V[i]), DFS(i,P-V[i]));
}

int main() {
    cin >> N >> S >> M;
    for (int i = 1; i <= N; i++) cin >> V[i];
    cout << DFS(0, S);
}