#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, A[1000];
int DP[1000];

int main() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];
    
    for (int i = 0; i < N; i++) {
        DP[i] = A[i];
        
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                DP[i] = max(DP[i], A[i]+DP[j]);
            }
        }
    }

    int M = 0;
    for (int i : DP) M = max(M,i);
    cout << M;
}