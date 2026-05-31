#include <bits/stdc++.h>

using namespace std;

const int MXN=1010101;

int N,seg[MXN*4];

int update(int n,int s,int e,int i,int x) {
    if(i<s||e<i) return seg[n];
    if(s==e) return seg[n]+=x;
    return seg[n]=update(n*2,s,(s+e)/2,i,x)+update(n*2+1,(s+e)/2+1,e,i,x);
}
int query(int n,int s,int e,int i) {
    if(e<=i) return seg[n];
    if(i<s) return 0;
    return query(n*2,s,(s+e)/2,i)+query(n*2+1,(s+e)/2+1,e,i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;while(N--) {
        int A,B,C;
        cin>>A>>B;
        if(A==1) {
            int l=1,r=MXN;
            while(l<r) {
                int m=(l+r)/2;
                if(query(1,0,MXN,m)<B) l=m+1; else r=m;
            }
            cout<<l<<'\n';
            B=l;C=-1;
        } else cin>>C;
        update(1,0,MXN,B,C);
    } 
}