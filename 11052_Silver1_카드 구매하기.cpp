#include <iostream>

using namespace std;

int N;
int P[10000], DP[10000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        int max = P[i];
        for (int j = 0; j < i; j++)
            if (DP[i-j-1]+P[j]> max) max = DP[i-j-1]+P[j];
        DP[i] = max;
    }

    cout << DP[N-1];

    return 0;
}