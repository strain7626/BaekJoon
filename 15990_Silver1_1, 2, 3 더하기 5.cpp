#include <iostream>
#define MOD 1000000009
using namespace std;

int n;
int DP[100001][3] = {{0,0,0},{1,0,0},{0,1,0},{1,1,1}};

int main() {

    for (int i = 4; i <= 100000; i++) {
        DP[i][0] = (DP[i-1][1]+DP[i-1][2])%MOD;
        DP[i][1] = (DP[i-2][0]+DP[i-2][2])%MOD;
        DP[i][2] = (DP[i-3][0]+DP[i-3][1])%MOD;
    }

    int T; cin >> T;
    while (T--) {
        cin >> n;
        cout << ((DP[n][0] + DP[n][1])%MOD + DP[n][2])%MOD << '\n';
    }
}