#include <iostream>
#define endl "\n"
using namespace std;

int DP[15][15];

int main() {
    int T; cin >> T;

    for (int i = 1; i <= 14; i++) DP[0][i] = i;
    for (int i = 1; i <= 14; i++) for (int j = 1; j <= 14; j++) DP[i][j] = DP[i-1][j] + DP[i][j-1];

    while (T--) {
        int N, K; cin >> N >> K;
        cout << DP[N][K] << endl;
    }
}