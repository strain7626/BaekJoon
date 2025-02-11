#include <iostream>
#define INF 1000000
using namespace std;

int DP[INF+1]; // 횟수
int pre[INF+1]; // 경로 추적

int main() {
    DP[1] = 0;
    pre[1] = 0;
    for (int i = 2; i <= INF; i++) {
        DP[i] = DP[i-1]; pre[i] = i-1;
        if (i%2 == 0 && DP[i/2] < DP[i]) {DP[i] = DP[i/2];pre[i] = i/2;}
        if (i%3 == 0 && DP[i/3] < DP[i]) {DP[i] = DP[i/3];pre[i] = i/3;}
        DP[i]+=1;
    }

    int N; cin >> N;
    cout << DP[N] << endl;

    int num = N;
    while (num) {
        cout << num << " ";
        num = pre[num];
    }
}