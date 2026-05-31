#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,K,A[1000000],ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>A[i];

    ll m=A[0],M=A[0],low=0;
    for(int i=1;i<N;i++) {
        m=min(m,A[i]);
        M=max(M,A[i]);
        if((i-low+1)*(M-m+1)>K) ans++,m=M=A[low=i];
    }
    cout<<ans+1;
}