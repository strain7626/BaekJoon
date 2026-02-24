#include <bits/stdc++.h>
#define MAX 2000000

using namespace std;

int N,T,X,seg[4*MAX],cnt[MAX+1];

int update(int n,int s,int e,int idx) {
    if(idx<s||e<idx) return seg[n];
    if(s==e) return seg[n]=cnt[idx];
    return seg[n]=update(n*2,s,(s+e)/2,idx)+update(n*2+1,(s+e)/2+1,e,idx);
}

int query(int n,int s,int e,int idx) {
    if(s==e) return s;
    if(seg[n*2]<idx) return query(n*2+1,(s+e)/2+1,e,idx-seg[n*2]);
    else return query(n*2,s,(s+e)/2,idx);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;while(N--) {
        cin>>T>>X;
        if(T==1) {
            cnt[X]++;
            update(1,1,MAX,X);
        } else {
            X=query(1,1,MAX,X);
            cout<<X<<'\n';

            cnt[X]--;
            update(1,1,MAX,X);
        }
    }
}