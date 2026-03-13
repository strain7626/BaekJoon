#include <bits/stdc++.h>

using namespace std;

int T,n,m,A[1001],B[1001];
long long ans;
map<int,int> cnt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>T>>n;
    for(int i=1;i<=n;i++) cin>>A[i],A[i]+=A[i-1];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>B[i],B[i]+=B[i-1];

    for(int i=1;i<=n;i++) for(int j=0;j<i;j++) cnt[A[i]-A[j]]++;
    for(int i=1;i<=m;i++) for(int j=0;j<i;j++) ans+=cnt[T-B[i]+B[j]];
    cout<<ans;
}