#include <bits/stdc++.h>
using namespace std;

int N, A[50], B[50];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i]; sort(A, A+N);
    for (int i = 0; i < N; i++) cin >> B[i]; sort(B, B+N);

    int ans = 0;
    for (int i = 0; i < N; i++) ans += A[i]*B[N-i-1];

    cout << ans;
}