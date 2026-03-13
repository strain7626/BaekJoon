#include <bits/stdc++.h>

using namespace std;

int N,M,A[100001],seg[400000];

int init(int n,int s,int e) {
    if(s==e) return seg[n]=s;

    int a=init(n*2,s,(s+e)/2),b=init(n*2+1,(s+e)/2+1,e);
    return seg[n]=(A[a]<=A[b]?a:b);
}

int update(int n,int s,int e,int idx) {
    if(idx<s||e<idx) return seg[n];
    if(s==e) return seg[n]=s;

    int a=update(n*2,s,(s+e)/2,idx),b=update(n*2+1,(s+e)/2+1,e,idx);
    return seg[n]=(A[a]<=A[b]?a:b);
}

int query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[n];
    
    int a=query(n*2,s,(s+e)/2,l,r),b=query(n*2+1,(s+e)/2+1,e,l,r);
    return A[a]<=A[b]?a:b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];

    A[0]=2e9;
    init(1,1,N);

    cin>>M;
    while(M--) {
        int n,i,j;cin>>n>>i>>j;
        if(n==1) A[i]=j,update(1,1,N,i);
        else cout<<query(1,1,N,i,j)<<'\n';
    }
}