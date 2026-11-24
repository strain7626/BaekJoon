#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MX=2e5+1;

int N,a[MX];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];

    ll pre[MX]={0};
    map<int,int> fst;

    ll ans=0,cnt=0;
    for(int i=1;i<=N;i++) {
        pre[i]=pre[i-1]+a[i];
        if(!fst.count(a[i])) fst[a[i]]=i;
        
        ll sum=pre[i]-pre[fst[a[i]]-1];
        if(sum>ans) ans=sum,cnt=0;
        if(sum==ans) cnt++;
    }
    cout<<ans<<' '<<cnt;
}