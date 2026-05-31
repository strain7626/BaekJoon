#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MXN=200005;

struct cell{int i,j,idx;};

int N,Q,A[MXN];
ll cnt[1000005],ans[MXN],tmp;
cell qry[MXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>Q;
    for(int i=1;i<=N;i++) cin>>A[i];
    for(int i=0;i<Q;i++) cin>>qry[i].i>>qry[i].j,qry[i].idx=i;

    int t=sqrt(N);
    sort(qry,qry+Q,[&](cell a,cell b){
        return (a.i/t==b.i/t?a.j<b.j:a.i<b.i);
    });

    auto add=[&](ll v){tmp-=cnt[v]*cnt[v]*v;cnt[v]++;tmp+=cnt[v]*cnt[v]*v;};
    auto sub=[&](ll v){tmp-=cnt[v]*cnt[v]*v;cnt[v]--;tmp+=cnt[v]*cnt[v]*v;};

    int l=1,r=0;
    for(int k=0;k<Q;k++) {
        int i=qry[k].i,j=qry[k].j,idx=qry[k].idx;
        while(l>i) add(A[--l]);
        while(r<j) add(A[++r]);
        while(l<i) sub(A[l++]);
        while(r>j) sub(A[r--]);

        ans[idx]=tmp;
    }

    for(int i=0;i<Q;i++) cout<<ans[i]<<'\n';
}