#include <iostream>
#include <cmath>
using namespace std;

int DP[70001][501];

int Solve(int N, int L) {
    if (DP[N][L]) return DP[N][L];
    if (N == 1) return L == 1;

    int i = 1;
    while (i*i < N)
        DP[N][L] += Solve(i++, L-1);

    return DP[N][L];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N, L; cin >> N >> L;
        cout << Solve(N, L) << '\n';
    }
}