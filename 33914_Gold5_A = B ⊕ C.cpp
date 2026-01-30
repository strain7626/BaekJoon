#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll X,Y,DP[1501][1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>X>>Y;

    if (X%2 || X>Y*2) {cout << 0;return 0;}

    int A=X/2, B=(Y-A)/3;
    
    DP[0][0] = 1;
    
    for (int a=0;a<=A;a++) for (int b=0;b<=B;b++) {
        if (a) DP[a][b] = DP[a-1][b]*3%MOD;
        if (b) DP[a][b] = (DP[a][b]+DP[a][b-1])%MOD;
    }

    cout << DP[A][B];
}