#include <iostream>
#define endl "\n"
using namespace std;

int N, A[1000], DP[1000]; 
int M = 0;

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[i] && DP[i] < DP[j]) DP[i] = DP[j];
        }
        DP[i]++;
        if (DP[i] > M) M = DP[i];
    }
    cout << M;
}