#include <bits/stdc++.h>
#define MAXN 1500000
using namespace std;

int N, T[MAXN+1], P[MAXN+1],
    DP[MAXN+60]; // i 일까지 끝낼 수 있는 최대 이익

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];

    for (int i = 1; i <= N; i++) {
        DP[i] = max(DP[i], DP[i-1]);
        DP[i+T[i]] = max(DP[i+T[i]], DP[i]+P[i]);
    }

    cout << max(DP[N],DP[N+1]);
}