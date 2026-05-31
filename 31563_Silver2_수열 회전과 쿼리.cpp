#include <bits/stdc++.h>

using namespace std;

long long N,Q,sum[200001],n=1;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for(int i=1;i<=N;i++) cin>>sum[i],sum[i]+=sum[i-1];

    while(Q--) {
        int q;cin>>q;
        if(q==1||q==2) {
            int k;cin>>k;
            n=(N+n+(q==1?-k:k)-1)%N+1;
        } else {
            int a,b;cin>>a>>b;
            a=(a+n-2)%N+1,b=(b+n-2)%N+1;
            cout<<sum[b]-sum[a-1]+(a<=b?0:sum[N])<<'\n';
        }
    }
}