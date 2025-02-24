#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n; cin >> n;
    int A[1000]; for (int i=0;i<n;i++) cin >> A[i];
    int DP[1000]; fill(DP,DP+n,0);
    DP[0] = 1;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && DP[j] > DP[i])
                DP[i] = DP[j];
        }
        DP[i]++;

        if (ans < DP[i]) ans = DP[i];
    }

    cout << ans;
}