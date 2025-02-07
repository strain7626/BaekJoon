#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 10000
using namespace std;

int N, M, m[100], c[100];
int DP[MAX+1]; // DP[j] -> 탐색했을때 j의 메모리 공간을 확보할 수 없으면 -1, 있으면 최소비용
int result = 2e9;

void Input() {
    cin >> N >> M;
    for (int i=0;i<N;i++) cin >> m[i];
    for (int i=0;i<N;i++) cin >> c[i];
}

void Reset() {
    for (int i = 0; i <= MAX; i++) DP[i] = -1;
}
void Solve() {
    Reset();
    DP[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = MAX; j >= m[i]; j--) {
            if (DP[j-m[i]] != -1)
                if (DP[j] == -1) DP[j] = DP[j-m[i]] + c[i];
                else DP[j] = min(DP[j], DP[j-m[i]] + c[i]);
        }
    }

    for (int i = M; i <= MAX; i++) if (DP[i] != -1) result = min(result, DP[i]);
}

int main() {
    Input();
    Solve();
    cout << result;
}