#include <bits/stdc++.h>

using namespace std;
using ll=long long;

vector<ll> prm;

void siv() {
    bool chk[45005]={0};
    for(int i=2;i<45005;i++) {
        if(chk[i]) continue;
        prm.push_back(i);
        for(int j=i*2;j<45005;j+=i) chk[j]=1;
    }
}

ll dfs(ll lim, int siz, int idx, ll cur, int dep) {
    ll res=0;
    for(int i=idx;i<siz;i++) {
        ll nxt=cur*prm[i]*prm[i];
        if(nxt>lim) break;
        res+=(dep%2==0?1:-1)*(lim/nxt)+dfs(lim,siz,i+1,nxt,dep+1);
    }
    return res;
}

ll cnt(ll val) {
    int siz=0;
    while(siz<prm.size()&&prm[siz]*prm[siz]<=val) siz++;
    return val-dfs(val,siz,0,1,0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll req;cin>>req;
    siv();
    
    ll ans=req;
    while(1) {
        ll val=cnt(ans);
        if(val==req) {cout<<ans<<'\n';break;}
        ans+=req-val;
    }
}