#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, A[501];
int DP[500][500]; // i ~ j 까지의 곱 최소
int result;

void Input() {
    cin >> N;
    for (int i=0;i<N;i++) {
        int a, b; cin >> a >> b;
        A[i] = a; A[i+1] = b;
    }
}

int DFS(int start, int end) {
    if (DP[start][end] != -1) return DP[start][end];

    DP[start][end] = 2e9;
    for (int i = start; i < end; i++) {
        DP[start][end] = min(DP[start][end], DFS(start, i) + DFS(i+1, end) + A[start] * A[i+1] * A[end+1]);
    }

    return DP[start][end];
}

void Solve() {
    for (int i = 0; i < N; i++) for (int j = i; j < N; j++) DP[i][j] = -1;
    for (int i = 0; i < N; i++) DP[i][i] = 0;
    result = DFS(0,N-1);
}

int main() {
    Input();
    Solve();
    cout << result << endl;
}