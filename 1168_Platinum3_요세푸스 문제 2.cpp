#include <bits/stdc++.h>

using namespace std;

int N,K,seg[400000];

int init(int n,int s,int e) {
    if(s==e) return seg[n]=1;
    return seg[n]=init(n*2,s,(s+e)/2)+init(n*2+1,(s+e)/2+1,e);
}

int query(int n,int s,int e,int idx) {
    seg[n]--;
    if(s==e) return s;
    if(seg[n*2]<idx) return query(n*2+1,(s+e)/2+1,e,idx-seg[n*2]);
    else return query(n*2,s,(s+e)/2,idx);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>K;
    int n=N,k=0;
    init(1,1,N);
    cout<<'<';
    while(n) cout<<query(1,1,N,(k=(k+K-1)%n--)+1)<<(n?", ":"");
    cout<<'>';
}