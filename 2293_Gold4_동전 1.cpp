#include <iostream>
#define endl "\n"
#define MAX 10000
using namespace std;

int n, k, V[100], DP[MAX+1] = {1};

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> V[i];

    for (int i = 0; i < n; i++) {
        for (int j = V[i]; j <= k; j++) {
            if (DP[j - V[i]]) DP[j] += DP[j - V[i]];
        }
    }

    cout << DP[k];
}