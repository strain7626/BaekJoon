#include <bits/stdc++.h>
using namespace std;

int N, arr[200], DP[200];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    DP[0] = 1;
    for (int i = 1; i < N; i++) {
        int M = 0;
        for (int j = 0; j < i; j++) if (arr[i] > arr[j]) M = max(M, DP[j]);
        DP[i] = M+1; 
    }

    int M = 0;
    for (int i = 0; i < N; i++) M = max(M, DP[i]);

    cout << N-M;
}