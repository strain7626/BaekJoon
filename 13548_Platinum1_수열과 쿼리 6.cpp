#include <bits/stdc++.h>

using namespace std;

const int MXN=100001;

struct cell{int i,j,idx;};

int N,M,A[MXN],num[MXN],cnt[MXN],ans[MXN];
cell Q[MXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i];
    cin>>M;
    for(int i=0;i<M;i++) cin>>Q[i].i>>Q[i].j,Q[i].idx=i;

    int t=sqrt(N);
    sort(Q,Q+M,[&](cell A,cell B){
        return (A.i/t==B.i/t?A.j<B.j:A.i<B.i);
    });

    int l=0,r=0,tmp=0;
    for(int k=0;k<M;k++) {
        auto [i,j,idx]=Q[k];
        while(l<i) --cnt[num[A[l++]]--]||tmp--;
        while(l>i) cnt[++num[A[--l]]]++||tmp++; 
        while(r<j) cnt[++num[A[++r]]]++||tmp++;
        while(r>j) --cnt[num[A[r--]]--]||tmp--;

        ans[idx]=tmp;
    }

    for(int i=0;i<M;i++) cout<<ans[i]<<'\n';
}