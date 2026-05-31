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
pos P[100000];

ll ccw(pos A,pos B,pos C) {
    ll t=(B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
    return (t>0)-(t<0);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>N;
    for(int i=0;i<N;i++) cin>>P[i].x>>P[i].y;

    sort(P,P+N);
    sort(P+1,P+N,[&](const pos &A,const pos &B){return !ccw(P[0],A,B)?abs(A.x-P[0].x)+abs(A.y-P[0].y)<abs(B.x-P[0].x)+abs(B.y-P[0].y):ccw(P[0],A,B)>0;});

    vector<int> ans={0,1};

    for(int i=2;i<N;i++) {
        while(ans.size()>=2&&ccw(P[ans[ans.size()-2]],P[ans[ans.size()-1]],P[i])<=0) ans.pop_back();
        ans.push_back(i);
    }

    cout<<ans.size();
}