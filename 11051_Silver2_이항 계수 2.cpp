#include <iostream>

using namespace std;

int N, K;
int DP[1001][1001];

int comb(int n, int k) {
    DP[0][0]=1;DP[1][0]=1;DP[1][1]=1;
    for (int i = 2; i <= n; i++) {
        DP[i][0]=1;DP[i][i]=1;
        for (int j = 1; j < i; j++)
            DP[i][j] = (DP[i-1][j]+DP[i-1][j-1])%10007;
    }
    return DP[n][k];
}

int main() {
    cin >> N >> K;
    cout << comb(N,K);

    return 0;
}