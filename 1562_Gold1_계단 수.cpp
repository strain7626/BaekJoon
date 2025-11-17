#include <iostream>
#define MOD 1000000000

using namespace std;

int N, ans;
int DP[101][10][(1<<10)-1];

int DFS(int cnt, int num, int bit) {
    if (cnt == N) return (bit == (1<<10)-1);
    if (DP[cnt][num][bit]) return DP[cnt][num][bit];

    if (num != 0) DP[cnt][num][bit] += DFS(cnt+1, num-1, bit|(1<<num-1));
    if (num != 9) DP[cnt][num][bit] += DFS(cnt+1, num+1, bit|(1<<num+1));
    DP[cnt][num][bit] %= MOD;

    return DP[cnt][num][bit];
}

int main() {
    cin >> N;

    ans = 0;
    for (int i = 1; i <= 9; i++) {  
        ans += DFS(1, i, (1<<i));
        ans %= MOD;
    }

    cout << ans;
}