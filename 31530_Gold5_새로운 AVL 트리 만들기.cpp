#include <bits/stdc++.h>

using namespace std;
using ll=long long;

const int MOD=1e9+7;
const int MXN=1e6+1;

ll H,S,DP1[MXN]={1,1},DP2[MXN]={1,1},DP3[MXN]={1,1};

void solve() {
    int tmp[3];
    
    cin>>H>>S;
    for(int i=0;i<S;i++) cin>>tmp[i];

    if(S==1) cout<<1;
    else if(S==2) cout<<(tmp[0]+tmp[1]?DP2[H]:DP1[H]);
    else cout<<DP3[H];
    cout<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<MXN;i++) {
        DP1[i]=DP1[i-1]*DP1[i-2]*2%MOD;
        DP2[i]=(DP2[i-1]*DP2[i-1]%MOD+DP2[i-1]*DP2[i-2]%MOD)%MOD;
        DP3[i]=(DP3[i-1]*DP3[i-1]%MOD+DP3[i-1]*DP3[i-2]*2%MOD)%MOD;
    }

    int T;cin>>T;while(T--) solve();
}