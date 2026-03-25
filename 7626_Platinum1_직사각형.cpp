#include <bits/stdc++.h>
#define MXN 200000

using namespace std;
using ll=long long;

struct line {
    int x,y1,y2,d;
    bool operator<(line &o) {return x<o.x;}
};

ll N,seg[8*MXN],cnt[8*MXN];
vector<int> y2i;
vector<line> L;

void update(int n,int s,int e,int l,int r,int t) {
    if(r<s||e<l) return;

    if(l<=s&&e<=r) cnt[n]+=t;
    else update(n*2,s,(s+e)/2,l,r,t),update(n*2+1,(s+e)/2+1,e,l,r,t);
    
    if(cnt[n]) seg[n]=y2i[e+1]-y2i[s];
    else seg[n]=(s==e?0:seg[n*2]+seg[n*2+1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0,x1,x2,y1,y2;i<N;i++) {
        cin>>x1>>x2>>y1>>y2;
        L.push_back({x1,y1,y2,1});
        L.push_back({x2,y1,y2,-1});
        y2i.push_back(y1);
        y2i.push_back(y2);
    }

    sort(y2i.begin(),y2i.end());
    y2i.erase(unique(y2i.begin(),y2i.end()),y2i.end());

    sort(L.begin(),L.end());

    ll ans=0;
    for(int i=0;i<N*2;i++) {
        auto [x,y1,y2,d]=L[i];
        y1=lower_bound(y2i.begin(),y2i.end(),y1)-y2i.begin();
        y2=lower_bound(y2i.begin(),y2i.end(),y2)-y2i.begin();

        if(i) ans+=(x-L[i-1].x)*seg[1];
        update(1,0,y2i.size()-2,y1,y2-1,d);
    }

    cout<<ans;
}