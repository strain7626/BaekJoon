#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,k,a[200001],p[200001],cnt[200001],P;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>p[i];
    for(int i=0;i<=k;i++) cnt[i]=0;
    P=a[p[0]];
    p[0]=0;p[k+1]=n;a[0]=P;

    int l=0,r=0;
    for(int i=0;i<=k;i++) {
        for(int j=p[i]+1;j<p[i+1];j++) if(a[j]!=P&&a[j-1]==P) cnt[i]++;
        
    }
    cout<<max(l,r)*2<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) solve();
}