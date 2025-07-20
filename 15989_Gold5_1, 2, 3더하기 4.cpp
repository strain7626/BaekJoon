#include <iostream>
using namespace std;

int DP[10001][3];

int main() {

    DP[1][0] = 1;
    DP[2][0] = 1; DP[2][1] = 1;
    DP[3][0] = 1; DP[3][1] = 1; DP[3][2] = 1;
    for (int i = 4; i <= 10000; i++) {
        DP[i][0] = DP[i-1][0];
        DP[i][1] = DP[i-2][0]+DP[i-2][1];
        DP[i][2] = DP[i-3][0]+DP[i-3][1]+DP[i-3][2];
    }

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << DP[n][0]+DP[n][1]+DP[n][2] << '\n';
    }
}