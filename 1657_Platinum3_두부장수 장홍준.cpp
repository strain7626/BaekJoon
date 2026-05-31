#include <bits/stdc++.h>

using namespace std;

int N,M,DP[14*14][(1<<14)],rnk[6][6]={{10,8,7,5,0,1},{8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{},{1,1,1,1,0,0}};
char S[14*14];

int go(int idx,int bit) {
    if(idx>=N*M) return bit==0?0:-1e9;

    int &res=DP[idx][bit];
    if(res!=-1) return res;

    res=go(idx+1,bit>>1);
    if(!(bit&1)) {
        if(!(bit&2)&&(idx%M<M-1)) res=max(res,go(idx+2,bit>>2)+rnk[S[idx]-'A'][S[idx+1]-'A']);
        if(idx/M<N-1) res=max(res,go(idx+1,bit>>1|1<<(M-1))+rnk[S[idx]-'A'][S[idx+M]-'A']);
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(DP,-1,sizeof(DP));
    cin>>N>>M;
    for(int i=0;i<N*M;i++) cin>>S[i];
    cout<<go(0,0);
}