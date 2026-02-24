#include <bits/stdc++.h>

using namespace std;

int N,C,M,sqrtN,A[300001],cnt[10001],ans[10000];

struct query {
    int idx,s,e;
    bool operator<(query &x) {
        return (s/sqrtN==x.s/sqrtN?e<x.e:s/sqrtN<x.s/sqrtN);
    }
};

query Q[10000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>C;
    for(int i=1;i<=N;i++) cin>>A[i];
    cin>>M;
    for(int i=0;i<M;i++)cin>>Q[i].s>>Q[i].e,Q[i].idx=i;
    
    sqrtN=sqrt(N);    
    sort(Q,Q+M);
    
    int s=Q[0].s,e=Q[0].s;cnt[A[Q[0].s]]++;
    for(int i=0;i<M;i++) {
        while(s<Q[i].s) cnt[A[s++]]--;
        while(s>Q[i].s) cnt[A[--s]]++;
        while(e<Q[i].e) cnt[A[++e]]++;
        while(e>Q[i].e) cnt[A[e--]]--;
        for(int k=1;k<=C;k++) if(cnt[k]>(e-s+1)/2) {
            ans[Q[i].idx]=k;
            break;
        }
    }

    for(int i=0;i<M;i++) {
        if(ans[i]) cout<<"yes "<<ans[i]<<'\n';
        else cout<<"no\n";
    }
}