#include <bits/stdc++.h>

using namespace std;

int N, L[1000], R[1000], DP[1000][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
    
    for (int x = 1; x <= 1000; x++) DP[0][x] = (x<L[0]||R[0]<x);
    
    for (int i = 1; i < N; i++) for (int x = 1; x <= 1000; x++)
        DP[i][x] = min(min(x>1?DP[i-1][x-1]:1001, DP[i-1][x]), x<1000?DP[i-1][x+1]:1001) + (x<L[i]||R[i]<x);   

    for (int x = 1; x <= 1000; x++) if (DP[N-1][x] < 2) {
        cout << "World Champion";
        exit(0);
    }
    cout << "Surrender";
}