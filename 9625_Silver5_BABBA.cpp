#include <bits/stdc++.h>
using namespace std;

int A[46] = {1}, B[46] = {0}, N;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        A[i] = B[i-1];
        B[i] = A[i-1] + B[i-1];
    }

    cout << A[N] << " " << B[N];
}