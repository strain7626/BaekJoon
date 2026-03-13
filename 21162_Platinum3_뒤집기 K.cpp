#include <bits/stdc++.h>
#define MXN 400000

using namespace std;

int N,K,A[MXN],sfx[MXN],rnk[MXN+1],tmp[MXN+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>A[i],A[N+i]=A[i];
    reverse(A,A+2*N);
    for(int i=0;i<2*N;i++) rnk[i]=A[i],sfx[i]=i;
    rnk[2*N]=-1;

    for(int k=1;k<=N;k*=2) {
        auto cmp=[k](int a,int b){
            if(rnk[a]!=rnk[b]) return rnk[a]<rnk[b];
            return rnk[min(2*N,a+k)]<rnk[min(2*N,b+k)];
        };

        sort(sfx,sfx+2*N,cmp);

        tmp[sfx[0]]=0;
        for(int i=1;i<2*N;i++) tmp[sfx[i]]=tmp[sfx[i-1]]+cmp(sfx[i-1],sfx[i]);
        for(int i=0;i<2*N;i++) rnk[i]=tmp[i];
    }

    for(int i=0,cnt=0;i<2*N;i++) {
        if(0<sfx[i]&&sfx[i]<N) cnt++;
        if(cnt==K) {
            for(int j=0;j<N;j++) cout<<A[sfx[i]+j]<<' ';
            break;
        }
    }
}