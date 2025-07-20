#include <iostream>
using namespace std;

int N, M, DP[41][2];
bool V[41];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        V[x] = 1;
    }

    DP[1][0] = 1;
    for (int i = 2; i <= N; i++) {
        DP[i][0] = DP[i-1][0]+DP[i-1][1];
        if (V[i-1] || V[i]) continue;
        DP[i][1] = DP[i-1][0];
    }

    cout << DP[N][0]+DP[N][1];
}