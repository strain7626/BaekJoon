#include <bits/stdc++.h>

using namespace std;
using ll=long long;

struct pos{
    ll x,y;
    bool operator<(const pos &o) {
        return (y==o.y?x<o.x:y<o.y);
    }
};

int N;
pos P[200000];

ll ccw(pos A,pos B,pos C) {
    ll t=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    return (t>0)-(t<0);
}

ll dist(pos A,pos B) {return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);}

void solve() {
    cin>>N;
    for(int i=0;i<N;i++) cin>>P[i].x>>P[i].y;
    
    sort(P,P+N);
    sort(P+1,P+N,[&](const pos &A,const pos &B){return !ccw(P[0],A,B)?abs(A.x-P[0].x)+abs(A.y-P[0].y)<abs(B.x-P[0].x)+abs(B.y-P[0].y):ccw(P[0],A,B)>0;});
    
    vector<int> ans={0,1};
    
    for(int i=2;i<N;i++) {
        while(ans.size()>=2&&ccw(P[ans[ans.size()-2]],P[ans[ans.size()-1]],P[i])<=0) ans.pop_back();
        ans.push_back(i);
    }
    
    int s=0,e=1,a=0,b=1,n=ans.size();
    for(int i=0;i<n*2;i++) {
        if(dist(P[ans[a]],P[ans[b]])<dist(P[ans[s]],P[ans[e]])) a=s,b=e;
        if(ccw(P[ans[s]],P[ans[(s+1)%n]],{P[ans[s]].x+P[ans[(e+1)%n]].x-P[ans[e%n]].x,P[ans[s]].y+P[ans[(e+1)%n]].y-P[ans[e%n]].y})>=0) e=(e+1)%n;
        else s=(s+1)%n;
    }
    cout<<P[ans[a]].x<<' '<<P[ans[a]].y<<' '<<P[ans[b]].x<<' '<<P[ans[b]].y<<'\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;cin>>t;while(t--) solve();
}