#include <iostream>

using namespace std;

int n, k;
int DP[10001], Coins[100];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        Coins[i] = t;
        if (t < 10001) DP[t] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) 
            if (i-Coins[j] > 0 && DP[i-Coins[j]]) {
                if (DP[i] == 0) {
                    DP[i] = DP[i-Coins[j]]+1;
                    continue;
                }
                if (DP[i] > DP[i-Coins[j]]+1)
                    DP[i] = DP[i-Coins[j]]+1;
            }
    }
    if (DP[k]) cout << DP[k];
    else cout << -1;

    return 0;
}