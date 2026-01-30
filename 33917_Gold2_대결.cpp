#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll N,A[1000000],B[1000000],P[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    for (int i=0;i<N;i++) cin >> A[i];
    for (int i=0;i<N;i++) cin >> B[i];

    for (int i=N-1;i>=0;i--) P[i]=P[i+1]+B[i]*(A[i]?1:-1);

    ll S=P[0],M=1;
    for (int i=1;i<N;i++) if (P[i]>0) S+=P[i],M++;

    cout << M << ' ' << S;
}