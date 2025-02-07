#include <iostream>
#include <algorithm>
#define endl "\n"
#define MAX 10000
using namespace std;

int N, M, m[100], c[100];
int DP[MAX+1]; // DP[j] -> j의 비용으로 얻을 수 있는 최대 메모리
int result;

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
        for (int j = MAX; j >= c[i]; j--) {
            if (DP[j-c[i]] != -1)
                if (DP[j] == -1) DP[j] = DP[j-c[i]] + m[i];
                else DP[j] = max(DP[j], DP[j-c[i]] + m[i]);
        }
    }

    for (int i = 0; i <= MAX; i++) if (DP[i] >= M) {
        result = i;
        break;
    }
}

int main() {
    Input();
    Solve();
    cout << result;
}