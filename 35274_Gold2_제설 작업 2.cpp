#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,M,L,A[100000],B[100000];

bool chk(ll X) {
    for(int i=0;i<N;i++) B[i]=A[i];
    
    ll cnt=0;
    for(int i=0;i<N;i++) {
        if(B[i]>=X) cnt+=B[i]/X,B[i]%=X;
        if(!B[i]) continue;
        
        ll tmp=X;
        for(int j=i;j<min(N,i+L);j++) if(tmp>=B[j]) tmp-=B[j],B[j]=0; else {B[j]-=tmp;break;}
        cnt++;
    }

    return cnt<=M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>L;
    for(int i=0;i<N;i++) cin>>A[i];
    
    ll l=1,r=1e18;
    while(l<r) {
        ll m=(l+r)/2;
        if(chk(m)) r=m;
        else l=m+1;
    }
    cout<<(chk(l)?l:-1);
}