#include <bits/stdc++.h>
using namespace std;

const int MAX=65537;

int N,K,A[250001],seg[MAX*4];
long long ans;

int update(int n,int s,int e,int i,int t) {
    if(i<s||e<i) return seg[n];
    if(s==e) return seg[n]+=t;
    return seg[n]=update(n*2,s,(s+e)/2,i,t)+update(n*2+1,(s+e)/2+1,e,i,t);
}
int query(int n,int s,int e,int k) {
    if(s==e) return s;
    if(seg[n*2]>=k) return query(n*2,s,(s+e)/2,k);
    return query(n*2+1,(s+e)/2+1,e,k-seg[n*2]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=1;i<=N;i++) {
        cin>>A[i];
        update(1,0,MAX,A[i],1);
        if(i<K) continue;
        
        int l=1,r=MAX,m;
        ans+=query(1,0,MAX,(K+1)/2);
        update(1,0,MAX,A[i-K+1],-1);
    }
    cout<<ans;
}