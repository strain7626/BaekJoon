#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=1000001;

ll n,a,b,c,x[MXN],s[MXN],dp[MXN],stk[MXN],xp[MXN];

ll f(ll t) {return a*t*t+b*t+c;}

double crx(int i,int j) {return (double)(a*(s[i]*s[i]-s[j]*s[j])-b*(s[i]-s[j])+dp[i]-dp[j])/(2*a*(s[i]-s[j]));}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++) cin>>x[i],s[i]=s[i-1]+x[i];

    for(int cnt=0,idx=1,i=1;i<=n;i++) {
        dp[i]=f(s[i]);

        if(!cnt) {stk[++cnt]=i;xp[cnt]=-1e9;continue;}

        while(idx<cnt&&xp[idx+1]<s[i]) idx++;
        dp[i]=max(dp[i],dp[stk[idx]]+f(s[i]-s[stk[idx]]));

        while(cnt&&xp[cnt]>crx(stk[cnt],i)) cnt--;
        stk[++cnt]=i;
        xp[cnt]=crx(stk[cnt-1],i);
        if(idx>cnt) idx=cnt;
    }

    cout<<dp[n];
}