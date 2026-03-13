#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll A,B,DP[56];

ll sum(ll N) {
    ll res=0,cnt=0;
    for(int i=55;i>=0;i--) {
        if(!((N>>i)&1)) continue;
        res+=DP[i]+1+(1LL<<i)*cnt++;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=0;i<55;i++) DP[i+1]=DP[i]*2+(1LL<<i);
    
    cin>>A>>B;
    cout<<sum(B)-sum(A-1);
}