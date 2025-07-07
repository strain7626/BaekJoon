#include <iostream>
#include <algorithm>

using namespace std;

int N, C[1000], DP[1000][1000][2];

int Solve(int l, int r, bool T) {
    if (DP[l][r][T]) return DP[l][r][T];
    if (l == r) return C[l]*T;

    if (T) return DP[l][r][1] = max(Solve(l+1,r,0)+C[l], Solve(l,r-1,0)+C[r]);
    else return DP[l][r][0] = min(Solve(l+1,r,1), Solve(l,r-1,1));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> C[i];
        cout << Solve(0,N-1,1) << '\n';
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) DP[i][j][0] = DP[i][j][1] = 0;
    }
}