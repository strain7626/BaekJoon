#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int mob[200005];

void siv() {
    mob[1]=1;
    for(int i=1;i<200005;i++) {
        for(int j=i*2;j<200005;j+=i) mob[j]-=mob[i];
    }
}

ll cnt(ll val) {
    ll res=0;
    for(ll i=1;i*i<=val;i++) res+=mob[i]*(val/(i*i));
    return val-res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll req;cin>>req;
    siv();
    
    ll l=1,r=4e10,ans=0;
    while(l<=r) {
        ll mid=l+(r-l)/2;
        if(cnt(mid)>=req) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}