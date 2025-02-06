#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAXLIMIT
using namespace std;

int N, W[30];
bool DP[30][40001];
bool result[40001];

void Input() {
    cin >> N;
    for (int i=0;i<N;i++) cin >> W[i];
}

void Solve() {
    DP[0][0] = true;
    DP[0][W[0]] = true;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= 40000; j++) {
            if (DP[i-1][j]) DP[i][j] = true;
            else if (j-W[i] >= 0 && DP[i-1][j-W[i]]) DP[i][j] = true;
            else if (j+W[i] <= 40000 && DP[i-1][j+W[i]]) DP[i][j] = true; 
        }
    }
}

void Reset() {
    for (int i=0;i<N;i++) for (int j=0;j<=40000;j++) DP[i][j] = false;
}

int main() {
    Input();
    Solve();
    for (int i=0;i<=40000;i++) result[i] += DP[N-1][i];
    Reset();
    reverse(W, W+N);
    Solve();
    for (int i=0;i<=40000;i++) result[i] += DP[N-1][i];
    int T; cin >> T;
    while (T--) {
        int num; cin >> num;
        if (result[num]) cout << "Y ";
        else cout << "N ";
    }
}