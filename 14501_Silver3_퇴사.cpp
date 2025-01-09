#include <iostream>

using namespace std;

int N, T, P;
int DP[16];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T >> P;
        if (i+T < N+1) DP[i+T] = max(DP[i+T], DP[i] + P);
        DP[i+1] = max(DP[i+1], DP[i]);
    }
    
    int M = 0;
    for (int i = 0; i < N+1; i++) if (DP[i] > M) M = DP[i];
    cout << M;

    return 0;
}