#include <bits/stdc++.h>

using namespace std;

const int MXN=1000001;

struct cell{int i,j,idx;};

int N,Q,A[MXN],num[MXN],ans[MXN];
cell qry[MXN];
vector<int> v;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i],v.push_back(A[i]);
    cin>>Q;
    for(int i=0;i<Q;i++) cin>>qry[i].i>>qry[i].j,qry[i].idx=i;

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=N;i++) A[i]=lower_bound(v.begin(),v.end(),A[i])-v.begin();

    int t=sqrt(N);
    sort(qry,qry+Q,[&](cell A,cell B){
        return (A.i/t==B.i/t?A.j<B.j:A.i<B.i);
    });

    int l=1,r=0,tmp=0;
    for(int k=0;k<Q;k++) {
        auto [i,j,idx]=qry[k];
        while(l>i) if(++num[A[--l]]==1) tmp++;
        while(r<j) if(++num[A[++r]]==1) tmp++;
        while(l<i) if(--num[A[l++]]==0) tmp--;
        while(r>j) if(--num[A[r--]]==0) tmp--;

        ans[idx]=tmp;
    }

    for(int i=0;i<Q;i++) cout<<ans[i]<<'\n';
}