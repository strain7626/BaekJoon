#include <bits/stdc++.h>
#define MXN 500000

using namespace std;

string S;
int N,sfx[MXN],lcp[MXN],rnk[MXN+1],tmp[MXN+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>S;
    N=S.size();

    for(int i=0;i<N;i++) sfx[i]=i,rnk[i]=S[i]-'a';
    rnk[N]=-1;

    for(int k=1;k<=N;k*=2) {
        auto cmp=[k](int a,int b){
            if(rnk[a]!=rnk[b]) return rnk[a]<rnk[b];
            return rnk[min(N,a+k)]<rnk[min(N,b+k)];
        };

        sort(sfx,sfx+N,cmp);

        tmp[sfx[0]]=0;
        for(int i=1;i<N;i++) tmp[sfx[i]]=tmp[sfx[i-1]]+cmp(sfx[i-1],sfx[i]);
        for(int i=0;i<N;i++) rnk[i]=tmp[i];
    }

    for(int i=0,h=0;i<N;i++) if(rnk[i]) {
        int j=sfx[rnk[i]-1];

        while(i+h<N&&j+h<N&&S[i+h]==S[j+h]) h++;
        lcp[rnk[i]]=h;
        if(h) h--;
    }

    for(int i=0;i<N;i++) cout<<sfx[i]+1<<' ';
    cout<<"\nx ";
    for(int i=1;i<N;i++) cout<<lcp[i]<<' ';
}