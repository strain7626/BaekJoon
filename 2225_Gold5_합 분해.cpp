#include <iostream>
#define endl "\n"
using namespace std;

int N,K,DP[201][201];

int main() {
    cin >> N >> K;

    for (int j = 0; j <= N; j++) DP[1][j] = 1;

    for (int i = 2; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                DP[i][j] = (DP[i][j]+DP[i-1][k])%1000000000;
            }
        }
    }

    cout << DP[K][N];
}