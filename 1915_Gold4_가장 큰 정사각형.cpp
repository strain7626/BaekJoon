#include <iostream>
using namespace std;

int DP[1001][1001]; // i,j에서 가장 큰 정사각형의 변의 길이

int min(int a, int b, int c) {
    if (a<=b && a<=c) return a;
    if (b<=a && b<=c) return b;
    return c;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
        char c; cin >> c;
        DP[i][j] = c-'0';
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (DP[i][j]) DP[i][j] = min(DP[i-1][j-1], DP[i-1][j], DP[i][j-1])+1;
        if (ans < DP[i][j]) 
            ans = DP[i][j];
    }
    
    cout << ans*ans;
}