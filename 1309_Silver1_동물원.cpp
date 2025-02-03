#include <iostream>
#define endl "\n"
#define MOD 9901
using namespace std;

long long DP[100000][2] = {{1,2}};


int main() {
    int N; cin >> N;
    
    for (int i = 1; i < N; i++) {
        DP[i][0] = ( DP[i-1][0] + DP[i-1][1] )%MOD;
        DP[i][1] = ( DP[i-1][0]*2 + DP[i-1][1] ) % MOD;
    }

    cout << (DP[N-1][0]+DP[N-1][1]) % MOD;
}