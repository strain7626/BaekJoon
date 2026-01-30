#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll N,DP[1000001][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    DP[1][0]=24,DP[1][1]=2;
    for (int i=2;i<=N;i++) DP[i][0]=(DP[i-1][0]*24+DP[i-1][1]*2)%MOD,DP[i][1]=(DP[i-1][0]*2+DP[i-1][1]*24)%MOD;

    cout << DP[N][0];
}