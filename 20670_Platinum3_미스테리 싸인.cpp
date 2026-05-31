#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll=long long;
using pos=pair<ll,ll>;

int N,M,K;

ll ccw(pos A,pos B,pos C) {return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);}

bool chk(vector<pos> &cvx,pos P) {
    if(!(ccw(cvx[0],cvx[1],P)>0&&ccw(cvx[0],cvx.back(),P)<0)) return 0;

    int idx=lower_bound(cvx.begin()+1,cvx.end(),P,[&](pos A,pos P){return ccw(cvx[0],A,P)>0;})-cvx.begin();

    return ccw(cvx[idx-1],cvx[idx],P)>0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N>>M>>K;
    vector<pos> A(N),B(M),C(K);

    for(auto &[x,y]:A) cin>>x>>y;
    for(auto &[x,y]:B) cin>>x>>y;
    for(auto &[x,y]:C) cin>>x>>y;

    int cnt=0;
    for(pos P:C) if(!chk(A,P)||chk(B,P)) cnt++;
    if(cnt) cout<<cnt; else cout<<"YES";
}