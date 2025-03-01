#include <iostream>
using namespace std;

int N, S;
int A[100001];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i-1];
    }

    int i = 0, j = 1;

    int ans = 0;
    while (j <= N) {
        if (A[j]-A[i] >= S) {
            ans = (ans == 0 ? j-i : min(ans, j-i));
            i++;
        } else j++;
    }

    cout << ans;
}