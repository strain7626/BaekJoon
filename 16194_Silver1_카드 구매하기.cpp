#include <bits/stdc++.h>
using namespace std;

int N, P[10001], DP[10001];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> P[i];

    for (int i = 1; i <= N; i++) {
        DP[i] = P[i];
        for (int j = 1; j < i; j++) DP[i] = min(DP[i], DP[j]+P[i-j]);
    }

    cout << DP[N];
}