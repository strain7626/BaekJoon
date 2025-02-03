#include <iostream>
#define endl "\n"
using namespace std;

int DP[100001];

int main() {
    for (int i = 1; i <= 100000; i++) {
        DP[i] = 2e9;

        int n = 1;
        while (i - (n*n) >= 0) {
            if (DP[i-(n*n)]+1 < DP[i]) DP[i] = DP[i-(n*n)]+1;
            n++;
        }
    }

    int N; cin >> N;
    cout << DP[N];
}