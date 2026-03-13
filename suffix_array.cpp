#include <bits/stdc++.h>
#define MXN 200000

using namespace std;

int N,A[MXN],sfx[MXN+1],rnk[MXN+1][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i],rnk[i][0]=A[i],sfx[i]=i;
    sfx[N]=N;
    rnk[N][0]=-1e9;

    int K=1;
    do {
        sort(sfx,sfx+N,[K](int a,int b){
            if(rnk[a][0]==rnk[b][0]) return rnk[min(N,a+K)][0]<rnk[min(N,b+K)][0];
            return rnk[a][0]<rnk[b][0];
        });

        rnk[sfx[0]][1]=0;
        for(int i=1;i<N;i++) rnk[sfx[i]][1]=rnk[sfx[i-1]][1]+!(rnk[sfx[i]][0]==rnk[sfx[i-1]][0]&&rnk[min(N,sfx[i]+K)][0]==rnk[min(N,sfx[i-1]+K)][0]);
        for(int i=0;i<N;i++) rnk[i][0]=rnk[i][1];
    }
    while((K*=2)<N);

    for(int i=0;i<N;i++) cout<<sfx[i]<<' ';cout<<'\n';
    for(int i=0;i<N;i++) cout<<rnk[i][0]<<' ';
    
}