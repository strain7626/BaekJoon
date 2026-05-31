#include <bits/stdc++.h>

using namespace std;

const int MOD=9901;

int N,M,DP[14*14][(1<<14)-1];

int go(int idx,int bit) {
    if(idx>=N*M) return idx==N*M&&bit==0;

    int &res=DP[idx][bit];
    if(res!=-1) return res;

    res=0;
    if(bit&1) res+=go(idx+1,bit>>1);
    else {
        if(!(bit&2)&&(idx%M<M-1)) res+=go(idx+2,bit>>2);
        res+=go(idx+1,bit>>1|1<<(M-1));
    }
    res%=MOD;

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(DP,-1,sizeof(DP));
    cin>>N>>M;
    cout<<go(0,0);
}