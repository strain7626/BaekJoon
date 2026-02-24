#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll N,seg[2000000];
pair<int,int> A[500000];

ll update(int n,int s,int e,int idx) {
    if(idx<s||e<idx) return seg[n];
    if(s==e) return seg[n]=1;
    return seg[n]=update(n*2,s,(s+e)/2,idx)+update(n*2+1,(s+e)/2+1,e,idx);
}
ll query(int n,int s,int e,int l) {
    if(e<l) return 0;
    if(l<=s) return seg[n];
    return query(n*2,s,(s+e)/2,l)+query(n*2+1,(s+e)/2+1,e,l);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i].first,A[i].second=i;
    sort(A,A+N);
        
    ll ans=0;
    for(int i=0;i<N;i++) ans+=query(1,0,N-1,A[i].second),update(1,0,N-1,A[i].second);
    cout<<ans;
}