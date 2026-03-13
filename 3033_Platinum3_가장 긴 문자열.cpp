#include <bits/stdc++.h>
#define MXN 200000

using namespace std;

string S;
int L,sfx[MXN],lcp[MXN],rnk[MXN+1],tmp[MXN+1];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>L>>S;

    for(int i=0;i<L;i++) sfx[i]=i,rnk[i]=S[i]-'a';
    rnk[L]=-1;

    for(int k=1;k<=L;k*=2) {
        auto cmp=[k](int a,int b){
            if(rnk[a]!=rnk[b]) return rnk[a]<rnk[b];
            return rnk[min(L,a+k)]<rnk[min(L,b+k)];
        };

        sort(sfx,sfx+L,cmp);

        tmp[sfx[0]]=0;
        for(int i=1;i<L;i++) tmp[sfx[i]]=tmp[sfx[i-1]]+cmp(sfx[i-1],sfx[i]);
        for(int i=0;i<L;i++) rnk[i]=tmp[i];
    }

    for(int i=0,h=0;i<L;i++) if(rnk[i]) {
        int j=sfx[rnk[i]-1];

        while(i+h<L&&j+h<L&&S[i+h]==S[j+h]) h++;
        lcp[rnk[i]]=h;
        if(h) h--;
    }

    cout<<*max_element(lcp,lcp+L);
}