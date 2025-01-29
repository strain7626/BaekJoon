#include <iostream>
#define endl "\n"
using namespace std;

int N;
long long DP[2][90] = {{},{1,}};


int main() {
    cin >> N;

    for (int i = 1; i < N; i++) {
        DP[0][i] = DP[0][i-1] + DP[1][i-1];
        DP[1][i] = DP[0][i-1];
    }

    cout << DP[0][N-1] + DP[1][N-1];
}