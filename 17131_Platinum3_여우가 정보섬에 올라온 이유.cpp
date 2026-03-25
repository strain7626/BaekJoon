#include <bits/stdc++.h>
#define MOD 1000000007
#define MXN 200000
#define x first
#define y second

using namespace std;

int N,seg[4*MXN],Q[MXN],chx[2*MXN+1],chy[2*MXN+1];
long long ans;
map<pair<int,int>,int> inp;
vector<tuple<int,int,int>> pos;

int update(int n,int s,int e,int idx,int val) {
    if(idx<s||e<idx) return seg[n];
    if(s==e) return seg[n]+=val;
    return seg[n]=update(n*2,s,(s+e)/2,idx,val)+update(n*2+1,(s+e)/2+1,e,idx,val);
}

long long query(int n,int s,int e,int l,int r) {
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[n];
    return query(n*2,s,(s+e)/2,l,r)+query(n*2+1,(s+e)/2+1,e,l,r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    for(int i=0,a,b;i<N;i++) cin>>a>>b,inp[{a,b}]++;
    
    for(auto [ab,c]:inp) pos.push_back({ab.x,ab.y,c});
    N=pos.size();
    for(int i=0;i<N;i++) Q[i]=i;

    sort(Q,Q+N,[&](int a,int b){
        auto [ax,ay,ac]=pos[a];
        auto [bx,by,bc]=pos[b];
        return (ay==by?ax<bx:ay>by);
    });
    for(int i=0;i<N;i++) {
        auto [a,b,c]=pos[Q[i]];
        ans=(ans+(query(1,0,N-1,0,Q[i])-chx[MXN+b])*(query(1,0,N-1,Q[i],N-1)-chy[MXN+a])*c)%MOD,update(1,0,N-1,Q[i],c);
        chx[MXN+b]+=c;
        chy[MXN+a]+=c;
    }
    
    cout<<ans;
}