#include <bits/stdc++.h>
#define MAXa 1000000
using namespace std;

int n, x;
bool A[MAXa+1];
int ans;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++) {
        int t; cin >> t;
        A[t] = 1;
    }
    cin >> x;

    ans = 0;
    int i = (x > MAXa ? x-MAXa : 1), j = x-i;
    while (i < j) {
        if (A[i] && A[j]) ans++;
        i++;j--;
    }
    cout << ans;
}