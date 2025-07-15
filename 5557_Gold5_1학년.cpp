#include <iostream>
#include <vector>
using namespace std;

int N, A[100];
long long DP[100][21];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    DP[0][A[0]] = 1;
    for (int i = 1; i < N-1; i++) for (int j = 0; j <= 20; j++) if (DP[i-1][j]) {
        if (j+A[i] >= 0 && j+A[i] <= 20) DP[i][j+A[i]] += DP[i-1][j];
        if (j-A[i] >= 0 && j-A[i] <= 20) DP[i][j-A[i]] += DP[i-1][j];
    }

    cout << DP[N-2][A[N-1]];
}