#include <iostream>
#define MOD 1000000009
#define endl "\n"
using namespace std;

long long DP[1000001] = {0, 1, 2, 4};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    for (int i = 4; i <= 1000000; i++)
        DP[i] = (DP[i-3] + DP[i-2] + DP[i-1])%MOD;
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << DP[n] << endl;
    }
}