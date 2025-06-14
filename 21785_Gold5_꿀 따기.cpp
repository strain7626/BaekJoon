#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, A[100001], S[100001];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }

    for (int i = 2; i < N; i++) {
        ans = max(ans, S[N-1] + S[i-1] - A[i]); // 꿀통 왼쪽
        ans = max(ans, 2*S[N] - S[i] - A[1] - A[i]); // 꿀통 오른쪽
        ans = max(ans, S[i]-A[1] + S[N-1]-S[i-1]); // 꿀통 가운데
    }

    cout << ans;
}