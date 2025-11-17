#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n; vector<int> DP(n);
    for (int i = 0; i < n; i++) cin >> DP[i];
    for (int i = 1; i < n; i++) DP[i] = max(DP[i], DP[i]+DP[i-1]);

    int ans = -1e9;
    for (int i = 0; i < n; i++) ans = max(ans, DP[i]);
    cout << ans;
}