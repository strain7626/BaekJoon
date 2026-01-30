#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,A[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=1;i<=N;i++) cin >> A[i];

    ll m=1e9,ans=0;
    for (int i=N;i>0;i--) ans += m=min(m,A[i]);
    cout << ans;
}