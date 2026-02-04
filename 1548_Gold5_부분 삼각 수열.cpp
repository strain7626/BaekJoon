#include <bits/stdc++.h>

using namespace std;

int N,A[50],ans=1;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N; for (int i=0;i<N;i++) cin>>A[i];
    sort(A, A+N);

    for (int i=0;i<N;i++) for (int j=i+1;j<N;j++)
        if (A[i]+A[i+1]>A[j]) ans=max(ans,j-i+1);

    cout << ans;
}